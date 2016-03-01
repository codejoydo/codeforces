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

VI g[105];
VII e;
int vs[105];

void dfs(int u){
	vs[u]=1;
	for(int i=0;i<SZ(g[u]);i++){
		int w = g[u][i];
		if(!vs[w])
			dfs(w);
	}
}

int main(){
	int n,a,b,c;
	si(n);
	for(int i=0;i<n;i++){
		si(c);si(a);si(b);
		if(c==1){
			e.PB(MP(a,b));
			for(int i=0;i<SZ(e)-1;i++){
				int c = e[i].F,d = e[i].S;
				if((c<a && a<d) || (c<b && b<d))
					g[SZ(e)].PB(i+1);
				if((a<c && c<b) || (a<d && d<b))
					g[i+1].PB(SZ(e));
			}
		}
		else if(c==2){
			SET(vs,0);
			dfs(a);
			if(vs[b])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
