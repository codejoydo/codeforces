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
const int N = 5000006;
int n;
LL H[N],RH[N],b1=256,p1=1e9+9,inv1,P1[N],bb1;
char s[N];
int D[N];
inline LL powmod(LL a,int n,LL mod){
	if(!n) return 1LL;
	if(n&1) return (a*powmod(a,n-1,mod))%mod;
	LL tp = powmod(a,n/2,mod);
	return (tp*tp)%mod;
}
typedef pair<LL,LL> PLL;
LL null = -1;
inline LL gethash(int l,int r){
	if(r>=n) return null;
	if(!l) return H[r];
	return ((H[r]-H[l-1]+p1)*P1[l])%p1;
}
inline LL getrhash(int l,int r){
	if(l<0) return null;
	if(r==n-1) return RH[l];
	return ((RH[l]-RH[r+1]+p1)*P1[n-1-r])%p1;
}
int main(){
	scanf("%s",s);
	n = strlen(s);
	inv1 = powmod(b1,p1-2,p1);
	P1[0] = 1;
	for(int i=1;i<n;i++){
		P1[i] = (P1[i-1]*inv1)%p1;
	}
	bb1 = 1;
	for(int i=0;i<n;i++){
		if(!i)
			H[i] = s[i];
		else
			H[i] = (H[i-1] + bb1*s[i]) % p1;
		bb1 = bb1*b1%p1;
	}
	bb1 = 1;
	for(int i=n-1;i>=0;i--){
		if(i==n-1)
			RH[i] = s[i];
		else
			RH[i] = (RH[i+1] + bb1*s[i]) % p1;
		bb1 = bb1*b1%p1;
	}
	int sum = 1;
	D[0] = 1;
	for(int i=1;i<n;i++){
		int len = i+1;
		int half = len/2;
		int mid = (len+1)/2;
		if(gethash(0,half-1)==getrhash(mid,mid+half-1)){
			D[i] = D[half-1] + 1;
		}
		sum += D[i];
	}
	printf("%d\n",sum);	
	return 0;
}
