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

bool win=true;

struct triplet{
	int a,b,c;
};

const int N=200005;
const int LOGN=19;
int vs[N],in[N];
VI g[N];
int V[N],U[N];
bool isbridge[N];
int cmpno=1,t=0,cmpn=1;
VI ng[N];
queue<int> dq[N];
int l[N];
int isin[N];
int isa[N],isb[N],isc[N];
int dp[N][LOGN];
int comp[N];

int adj(int u,int e){
	return (U[e]==u)?(V[e]):(U[e]);
}

int dfs1(int u,int edge){
	vs[u]=1;
	comp[u]=cmpn;
	in[u]=t++;
	int dbe=in[u];
	for(int i=0;i<SZ(g[u]);i++){
		int e=g[u][i];
		int w=adj(u,e);
		if(!vs[w])
			dbe=min(dbe,dfs1(w,e));
		else if(e!=edge)
			dbe=min(dbe,in[w]);
	}
	if(dbe==in[u] && edge!=-1){
		trace(u,edge);
		isbridge[edge]=1;
	}
	return dbe;
}

void dfs2(int v){
	int cc=cmpno;
	dq[cc].push(v);
	vs[v]=1;
	while(!dq[cc].empty()){
		int u=dq[cc].front();
		isin[u]=cc;
		dq[cc].pop();
		for(int i=0;i<SZ(g[u]);i++){
			int e=g[u][i];
			int w=adj(u,e);
			if(vs[w]) continue;
			if(isbridge[e]){
				cmpno++;
				ng[cmpno].PB(cc);
				ng[cc].PB(cmpno);
				dfs2(w);
			}
			else{
				dq[cc].push(w);
				vs[w]=1;
			}
		}
	}
}

void dfs3(int u){
	vs[u]=1;
	for(int i=0;i<SZ(ng[u]);i++){
		int w=ng[u][i];
		if(!vs[w]){
			l[w]=l[u]+1;
			dp[w][0]=u;
			dfs3(w);
		}
	}
}

int lca(int a,int b){ 
	if(l[a]>l[b])
				swap(a,b);
	int d=l[b]-l[a];
	for(int i=0;i<LOGN;i++)
		if((1<<i)&d)
			b=dp[b][i];
	trace(a,b);
	if(a==b)
		return a;
	for(int i=LOGN-1;i>=0;i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i];
			b=dp[b][i];
		}   
	}
	return dp[a][0];
}

struct triplet dfs4(int u){
	vs[u]=1;
	trace(u);
	struct triplet t;
	t.a=isa[u],t.b=isb[u],t.c=isc[u];
	for(int i=0;i<SZ(ng[u]);i++){
		int w=ng[u][i];
		if(!vs[w]){
			struct triplet st=dfs4(w);
			t.a+=st.a;
			t.b+=st.b;
			t.c+=st.c;
		}
	}
	trace(u,t.a,t.b,t.c);
	int d1=t.a-t.c,d2=t.b-t.c;
	if(d1>0 && d2>0)
		win=false;
	return t;
}

int main(){
	int n,m,q;
	si(n);si(m);si(q);
	for(int i=0;i<m;i++){
		int a,b;
		si(a);si(b);
		g[a].PB(i);
		g[b].PB(i);
		U[i]=a;
		V[i]=b;
	}
	for(int i=1;i<=n;i++){
		if(!vs[i]){
			dfs1(1,-1);
			cmpn++;
		}
	}
	SET(vs,0);
	for(int i=1;i<=n;i++){
		if(!vs[i]){
			dfs2(1);
			cmpno++;
		}
	}
	SET(vs,0);
	for(int i=1;i<cmpno;i++){
		if(!vs[i]){
			l[i]=0;
			dp[i][0]=i;
			dfs3(i);
		}
	}

	for(int j=1;j<LOGN;j++)
		for(int i=1;i<cmpno;i++)
			dp[i][j]=dp[dp[i][j-1]][j-1];

	for(int i=0;i<q;i++){
		int a,b,c,u,v,w;
		si(a);si(b);
		if(comp[a]!=comp[b]){
			cout << "No" << endl;
			return 0;
		}
		u=isin[a],v=isin[b];
		if(u==v) continue;
		c=lca(u,v);
		trace(u,v,c);
		isa[u]++;
		isb[v]++;
		isc[c]++;
	}
	SET(vs,0);
	for(int i=1;i<cmpno;i++){
		if(!vs[i])
			dfs4(i);
	}
	if(win)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
