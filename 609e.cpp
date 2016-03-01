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

vector< pair< II,II > > e;
LL ans[200005];
int par[200005];
int vs[200005];
int l[200005];
int dp[200005][20];
int dp1[200005][20];
VII g[200005];

int root(int x){ return par[x] == x ? x : par[x]=root(par[x]); }

int merge(int x,int y){
	if((x = root(x)) == (y = root(y))) return 0;
	if(x>y) swap(x,y);
	par[y] = x;
	return 1;
}

void dfs(int u){
	vs[u] = 1;
	for(int i=0;i<SZ(g[u]);i++){
		int w = g[u][i].F,wt = g[u][i].S;
		if(!vs[w]){
			l[w] = l[u]+1;
			dp[w][0] = u;
			dp1[w][0] = g[u][i].S;
			dfs(w);
		}
	}
}

int lca(int a,int b){ 
	int la=l[a],lb=l[b];
	int d=la-lb;
	if(d<0){
		d*=-1;
		swap(a,b);
	}
	for(int j=0;j<20;j++){
		if(!d) break;
		if(d&1){
			a=dp[a][j];
		}   
		d/=2;
	}
	trace(a,b);
	if(a==b)
		return a;
	for(int i=19;i>=0;i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i];
			b=dp[b][i];
			trace(a,b,i);
		}
	}
	return dp[a][0];
}

int max_edge(int a,int d){
	int ret = 0;
	if(d==0) return -1;
	for(int j=0;j<20;j++){
		if(!d) break;
		if(d&1){
			ret = max(ret,dp1[a][j]);
			a=dp[a][j];
		}   
		d/=2;
	}
	return ret;
}

int main(){
	int n;cin>>n;
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		e.PB(MP(MP(c,i),MP(a,b)));	
	}
	sort(ALL(e));
	int cnt = 0;
	for(int i=0;i<=n;i++) par[i] = i;
	LL sum = 0;
	for(int i=0;i<m;i++){
		int a = e[i].S.F, b = e[i].S.S, c = e[i].F.F, d = e[i].F.S;
		if(root(a)!=root(b)){
			merge(a,b);
			sum += c;
			g[a].PB(MP(b,c));		
			g[b].PB(MP(a,c));	
			cnt++;	
		}
		if(cnt == n-1) break;
	}
	dp[1][0]=1;
	dfs(1);
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			dp1[i][j]=max(dp1[dp[i][j-1]][j-1],dp1[i][j-1]);
			trace(i,j,dp1[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		int a = e[i].S.F, b = e[i].S.S, c = e[i].F.F, d = e[i].F.S;
		int v = lca(a,b);
		trace(v,a,b,dp[a][1],dp[b][1]);
		int edge = max(max_edge(a,l[v]-l[a]), max_edge(b,l[v]-l[b]));
		trace(max_edge(a,l[v]-l[a]));
		trace(max_edge(b,l[v]-l[b]));
		trace(edge);
		ans[d] = sum - edge + c;
	}
	for(int i=0;i<m;i++) lldout(ans[i]);
	return 0;
}
