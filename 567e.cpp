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

//#define TRACE

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

const LL inf=2e18;
vector< pair< II,LL > > e;
vector< pair< int,LL > > g[200005],ng[200005],rg[200005];
LL s[200005],d[200005];
int vs[200005];
int ans[100005];

int in[200005],p[200005],t=0,m[100005];
int dfs(int u){
	vs[u]=1;
	in[u]=t++;
	int dbe=in[u];
	for(int i=0;i<SZ(ng[u]);i++){
		int w=ng[u][i].F,index=ng[u][i].S;
		if(!vs[w]){
			ans[index]=1;
			m[index]=1;
			p[w]=u;
			int be=dfs(w);
			if(be==in[w]){
				trace(u,w);
				ans[index]=2;
			}
			else
				dbe=min(dbe,be);
		}
		else if(!m[index]){
			ans[index]=1;
			dbe=min(dbe,in[w]);
		}
	}
	return dbe;
}

int main(){
	int n,m,start,finish,a,b;
	LL c;
	si(n);si(m);si(start);si(finish);
	for(int i=0;i<m;i++){
		si(a);si(b);sll(c);
		g[a].PB(MP(b,c));
		rg[b].PB(MP(a,c));
		e.PB(MP(MP(a,b),c));
	}

	set< pair< LL,int > > q;

	/* dijkstra from source */
	for(int i=1;i<=n;i++){
		s[i]=inf;
		vs[i]=0;
	}
	s[start]=0;
	q.insert(MP(s[start],start));
	while(!q.empty()){
		int u=(*q.begin()).S;
		q.erase(q.begin());
		vs[u]=1;
		for(int i=0;i<SZ(g[u]);i++){
			int w=g[u][i].F;
			LL edge=g[u][i].S;
			if(s[u]+edge<s[w]){
				s[w]=s[u]+edge;
				q.insert(MP(s[w],w));
			}
		}
	}

	/* dijkstra from finish */
	for(int i=1;i<=n;i++){
		d[i]=inf;
		vs[i]=0;
	}
	d[finish]=0;
	q.insert(MP(d[finish],finish));
	while(!q.empty()){
		int u=(*q.begin()).S;
		q.erase(q.begin());
		vs[u]=1;
		for(int i=0;i<SZ(rg[u]);i++){
			int w=rg[u][i].F;
			LL edge=rg[u][i].S;
			if(d[u]+edge<d[w]){
				d[w]=d[u]+edge;
				q.insert(MP(d[w],w));
			}
		}
	}

	for(int i=0;i<SZ(e);i++){
		a=e[i].F.F,b=e[i].F.S,c=e[i].S;
		if(s[a]+c+d[b]==s[finish]){
			ng[a].PB(MP(b,i));
			ng[b].PB(MP(a,i));
			trace(a,b);
		}
	}
	/*
	for(int i=0;i<n;i++) 
		cout << s[i+1] << ' ';
	cout << endl;

	for(int i=0;i<n;i++) 
		cout << d[i+1] << ' ';
	cout << endl;
	*/
	SET(vs,0);
	dfs(start);

	for(int i=0;i<SZ(e);i++){
		if(ans[i]==2)
			cout << "YES" << endl;
		else{
			a=e[i].F.F,b=e[i].F.S,c=e[i].S;
			if(s[a]==inf||d[b]==inf){
				cout << "NO" << endl;
				continue;
			}
			int diff=s[a]+c+d[b]-s[finish]+1;
			trace(a,b,s[a],d[b],c,diff);
			if(diff<c)
				cout << "CAN " << diff << endl;
			else 
				cout << "NO" << endl;
		}
	}

	return 0;
}
