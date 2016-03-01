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

VI g[200005];
int vs[200005];
int deg[200005];
int m,node;

void dfs(int u,int d){
	vs[u] = 1;
	if(d>m){
		node = u;
		m = d;
	}
	for(int i=0;i<SZ(g[u]);i++){
		int w = g[u][i];
		if(!vs[w]) dfs(w,d+1);
	}
}

int main(){
	bool fl = false;
	LL n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
		deg[a]++;
		deg[b]++;
		if(deg[a]==n-1) fl = true;
		if(deg[b]==n-1) fl = true;
	}
	LL ans;
	if(x>y and fl == false){
		ans = (n-1)*y;
	}
	else if(fl==true and x>y){
		ans = (n-2)*y + x; 
	}
	else{
		
	}	
	cout<<ans<<endl;
	return 0;
}
