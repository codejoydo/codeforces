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

LL cnt[200005];
set<LL> s;
const LL mod = 1e9+7;
int main(){
	int n;
	cin>>n;
	LL num = 1;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		num *= a;
		num %= mod;
		s.insert(a);
		cnt[a]++;
	}
	LL prod = 1;
	for(auto i=s.begin();i!=s.end();i++){
		LL tp = cnt[*i]; ++tp;
		prod *= tp;
		prod %= mod;
	}
	trace(prod,num);
	if(prod%2==1) num = sqrt((double)num); 
	else prod /= 2;
	LL ans = 1;
	for(LL i=0;i<prod;i++){
		ans *= num;
		//trace(ans);
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
