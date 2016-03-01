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

VI g[3005];
int vs[3005],cnt[3005];
int ans,start;

void dfs(int u,int d){
	if(d>2)
		return;
	vs[u]=1;
	if(d==2)
		cnt[u]++;
//	trace(u,d);
	if(d<2)
	for(int i=0;i<SZ(g[u]);i++){
		int w = g[u][i];
		if(w==start)
			continue;
		if(!vs[w]||d==0)
			dfs(w,d+1);
		else{
			if(d==1){
				ans+=cnt[w];
				cnt[w]++;
			}
		}
	}
}

int main(){
	ans=0;
	int n,m,a,b;
	si(n);si(m);
	for(int i=0;i<m;i++){
		si(a);si(b);
		g[a].PB(b);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			vs[i]=0;
			cnt[i]=0;
		}
		start=k;
		dfs(k,0);
	}
	dout(ans);
	return 0;
}
