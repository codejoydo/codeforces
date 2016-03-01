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

int dp[500005][25];
int lg=20;
int main(){
	int n,k;
	si(n);si(k);
	for(int i=0;i<20;i++){
		dp[n][i]=1;
	}
	for(int i=0;i<n;i++) si(dp[i][0]);
	if(k==1){
		cout << n << endl;
		return 0;
	}
	for(int j=1;j<lg;j++){
		for(int i=0;i<n;i++){
			dp[i][j]=__gcd(dp[i][j-1],dp[min(i+(1<<(j-1)),n)][j-1]);
			trace(i,j,dp[i][j]);
		}
	}
	int lmax=0;
	for(int i=0;i<n;i++){
		int j=i;
		trace(i);
		for(int d=lg;d>=0;d--){
			if(dp[j][d]>=k){
				j=(j-1)+(1<<d);
				trace(j,d,j-1,1<<d);
				lmax=max(j-i+1,lmax);
			}
		}
	}		
	cout << lmax << endl;
	return 0;
}
