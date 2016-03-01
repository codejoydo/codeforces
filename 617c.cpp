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

pair<LL,int> a[2005];
pair<LL,int> b[2005];
int main(){
	LL n, x1, y1, x2, y2;
	cin>>n>>x1>>y1>>x2>>y2;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[i]=MP((x1-x)*(x1-x)+(y1-y)*(y1-y),i);
		b[i]=MP((x2-x)*(x2-x)+(y2-y)*(y2-y),i);
	}
	sort(a,a+n);
	sort(b,b+n);
	LL m=1e17;
	for(int i=0;i<n+1;i++){
		set<int> s;
		LL r1=0,r2=0;
		if(i<n){
			for(int j=0;j<=i;j++){
				s.insert(a[j].S);
				trace(a[j].F,a[j].S);
			}
		}
		else r1 = 0;
		if(SZ(s)==n){
			r1 = a[i].F;
			m = min(r1,m);
		}
		for(int j=0;j<n;j++){
			trace(b[j].F,b[j].S);
			s.insert(b[j].S);
			if(SZ(s)==n){
				r1 = a[i].F;
				r2 = b[j].F;
				m = min(r1+r2,m);
				break;
			}
		}		
	}
	cout<<m<<endl;
	return 0;
}
