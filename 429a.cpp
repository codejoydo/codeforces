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
//4FILE *fout = freopen("out","w",stdout);

VI G[100005];
int VS[100005],A[100005],B[100005];
int ANS;
VI V;
bool C1,C2;

void dfs(int u,int l){
	VS[u] = 1;
	bool fl = false,C;
	C = l&1 ? C1 : C2;
	A[u] = C ? 1-A[u] : A[u];
	if(A[u] != B[u]){
	 	C = C ? false : true;
		fl = true;
		ANS++;
		V.PB(u);
	}
	for(int i=0;i<SZ(G[u]);i++){
		int w = G[u][i];
		if(!VS[w]){
		 	dfs(w,l+1);
		}
	}
	if(fl){
		if(l&1) C1 = C1 ? false : true;
		else C2 = C2 ? false : true;
	}
}	

int main(){
	int n;si(n);
	for(int i=0;i<n-1;i++){
		int a,b;si(a);si(b);
		G[a].PB(b);
		G[b].PB(a);
	}
	for(int i=1;i<=n;i++) si(A[i]);
	for(int i=1;i<=n;i++) si(B[i]);
	dfs(1,1);
	dout(ANS);
	for(int i=0;i<SZ(V);i++) dout(V[i]);
	return 0;
}
