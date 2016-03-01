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

int A[300005];
int B[300005];

int f(int x){ return B[x] == x ? x : B[x] = f(B[x]); }

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n+4;i++) B[i] = i;
	for(int i=0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		int j = f(l);
		while(j<=r){
			if(j==x) j++;
			else{
				A[j] = x;
				B[j] = j+1;
			}
			j = f(j);	
		}
	}
	for(int i=1;i<=n;i++) cout<<A[i]<<' '; cout<<endl;
	return 0;
}
