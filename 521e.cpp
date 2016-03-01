//joyneel
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int vs[200005],stab[200005],p[200005],save[200005],in[200005];
VI g[200005];
int t=0,win=0;
int x,y,z,ys,zs;
VI path[3];

int dfs(int u){
	//trace(u);
	VII tp;
	vs[u]=1;
	save[t]=u;
	in[u]=t++;
	int dbe = in[u];
	for(int i=0;i<SZ(g[u]);i++){
		if(SZ(tp)>=2) break;
		int w = g[u][i];
		if(!vs[w]){												
			//ng[u].PB(w);
			p[w]=u;
			//cout <<u << "->" << w << endl;
			int be = dfs(w);								
			if(be<in[u]){										
				//trace(save[be],stab[save[be]]);
				tp.PB(MP(save[be],stab[save[be]]));							
			}
			dbe = min(dbe,be);							
		}
		else if(vs[w] && w!=p[u]){				
			//trace(w,u);
			if(in[w]<in[u])									
				stab[w]=u;										 
			dbe = min(dbe,in[w]);					
			tp.PB(MP(w,u));
		}
	}
	//trace(SZ(tp),u);
	if(SZ(tp)>=2 && win==0){
		win=1;
		x=u,y=tp[0].F,z=tp[1].F,ys=tp[0].S,zs=tp[1].S;
		if(in[y]>in[z]){ swap(y,z); swap(ys,zs); }
		int pt=x;
		while(pt!=p[z]){
			path[0].PB(pt);
			pt=p[pt];
			//if(pt==0) break;
			//trace(pt);
		}
		reverse(path[0].begin(),path[0].end());
		path[1].PB(z);
		pt=zs;
		while(pt!=p[x]){
			path[1].PB(pt);
			pt=p[pt];
			//if(pt==0) break;
			//trace(pt);
		}
		pt=z;
		while(pt!=p[y]){
			path[2].PB(pt);
			pt=p[pt];
			//if(pt==0) break;
			//trace(pt);
		}
		pt=ys;
		while(pt!=p[x]){
			path[2].PB(pt);
			pt=p[pt];
			//if(pt==0) break;
			//trace(pt);
		}
		//trace(u,win,x,y,ys,z,zs);
	}
	return dbe;
}
/*
VI path,path1;
int dx;
void bar(int u){
	//trace(u);
	vs[u]=1;
	path.PB(u);
	if(u==z){
		for(int i=0;i<SZ(path);i++) path1.PB(path[i]);
	}
	if(u==x){
		dx=SZ(path);
		cout << SZ(path)-SZ(path1)+1 << ' ';
		for(int i=SZ(path1)-1;i<SZ(path);i++) printf("%d ",path[i]);
		cout << endl;
	}
	if(u==zs){
		cout << SZ(path)-dx+2 << ' ';
		printf("%d ",z);
		for(int i=SZ(path)-1;i>=dx-1;i--) printf("%d ",path[i]);
		printf("\n");
	}
	if(u==ys){
		cout << SZ(path)-dx+1+SZ(path1) << ' ';
		for(int i=SZ(path1)-1;i>=0;i--) printf("%d ",path1[i]);
		for(int i=SZ(path)-1;i>=dx-1;i--) printf("%d ",path[i]);
		printf("\n");
	}
	for(int i=0;i<SZ(ng[u]);i++){
		int w=ng[u][i];
		if(!vs[w]) bar(w);
	}
	path.pop_back();
}*/

int main(){
	SET(p,0);
	int n,m,a,b;
	si(n);si(m);
	for(int i=0;i<m;i++){
		si(a);si(b);
		g[a].PB(b);
		g[b].PB(a);
	}
	x=-1;
	for(int i=1;i<=n;i++){
		if(!vs[i]){
			dfs(i);
		}
	}
	if(win){
		cout<<"YES"<<endl;
		cout<<(int)SZ(path[0])<<' ';
		for(int i=0;i<SZ(path[0]);i++) printf("%d ",path[0][i]);
		cout<<endl;
		cout<<(int)SZ(path[1])<<' ';
		for(int i=0;i<SZ(path[1]);i++) printf("%d ",path[1][i]);
		cout<<endl;
		cout<<(int)SZ(path[2])<<' ';
		for(int i=0;i<SZ(path[2]);i++) printf("%d ",path[2][i]);
		cout<<endl;
		/*cout<<"YES"<<endl;
		SET(vs,0);
		if(in[y]>in[z]){ swap(y,z); swap(ys,zs); }
		//trace(x,y,ys,z,zs);
		bar(y);*/
	}
	else cout<<"NO"<<endl;
	return 0;
}
