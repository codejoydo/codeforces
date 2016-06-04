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
string s;
int a[100005],b[100005],A[100005],B[100005];
int main(){
	int n,k;
	cin>>n>>k;
	cin>>s;
	s = " " + s;
	int ca = 0,cb = 0;
	for(int i=1;i<=n;i++){
		if(s[i] == 'a'){
			++ca;
		}
		else if(s[i] == 'b'){
			++cb;
		}
		a[i] = ca;
		b[i] = cb;
	}
	int mx = 0;
	int l=1,r=n;
	while(l<=r){
		int m = l+r;
		m /= 2;
		int fl = 0;
		for(int i=1;i<=n-m+1;i++){
			if(a[i+m-1]-a[i-1]<=k){
				fl = 1;
				break;
			}
		}
		if(fl) mx = max(mx,m),l = m+1;
		else r = m-1;
	}
	l=1,r=n;
	while(l<=r){
		int m = l+r;
		m /= 2;
		int fl = 0;
		for(int i=1;i<=n-m+1;i++){
			if(b[i+m-1]-b[i-1]<=k){
				fl = 1;
				break;
			}
		}
		if(fl) mx = max(mx,m),l = m+1;
		else r = m-1;
	}
	dout(mx);
	return 0;
}
