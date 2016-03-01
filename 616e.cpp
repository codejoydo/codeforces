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

const LL root = 3162277;
const LL mod = 1e9+7;

LL powmod(LL a,LL b){
	if(b==0)
		return 1;
	LL tp=powmod(a,b/2);
	tp*=tp;
	tp%=mod;
	if(b&1){
		tp*=a;
		tp%=mod;
	}
	return tp;
}

int main(){
	LL inv = powmod(2,mod-2);
	LL n,m;
	cin>>n>>m;
	LL ans = 0,add = 0;
	if(m>n){
		add = (((m-n)%mod)*(n%mod)) % mod;
		m = n;
	}
	ans += ((m%mod)*(n%mod)) % mod;
	ans %= mod;
	LL sub = 0;
	LL END = min(root,m);
	for(LL i=1;i<=END;i++){
		sub = (sub + ((n/i)*i) % mod) % mod;
	}
	END++;
	for(LL i=END;i<=m;i++){
		LL l,r,v = n/i;
		v %= mod;
		l = max(i, n/(v+1));
		r = min(m, n/v);
		LL x = r%mod;
		x *= ((r+1)%mod); 
		x %= mod;
		x *= inv;
		x %= mod;
		LL y = l%mod;
		y *= ((l-1+mod)%mod); 
		y %= mod;
		y *= inv;
		y %= mod;
		//trace(l,r,v);
		LL z = (((x-y+mod)%mod)*v) % mod;
		sub = (sub + z) % mod;
		i = r;
	}
	//trace(ans,sub);
	ans = (ans - sub + add + mod) % mod;
	cout<<ans<<endl;
	return 0;
}
