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

bool collide(int a,int b,int c,int d){
	trace(b,c,a,d);
	if(b<c||a>d) return false;
	return true;
}

int A[2000],B[2000];
int main(){
	int a,ta,b,tb;
	cin>>a>>ta>>b>>tb;
	for(int i=5*60;i<=23*60+59;i+=a) A[i] = 1;
	for(int i=5*60;i<=23*60+59;i+=b) B[i] = 1;
	int h = 0, m = 0;
	scanf("%d:%d",&h,&m);
	int st = h*60+m;
	int ans = 0;
	for(int i=0;i<=1500;i++){
		if(B[i]){
			if(collide(st,st+ta,i,i+tb) and st!=i+tb and i!=st+ta){
				trace(st+ta,i,st,i+tb);
				ans++;
			}
		}
	}
	dout(ans);
	return 0;
}
