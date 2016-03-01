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

pair<LL,LL> a[100005];
LL d[100005];
LL b[100005];
double ans;
int main(){
	int n;
	LL p;
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>a[i].F>>a[i].S;
		b[i] = a[i].S/p - (a[i].F-1)/p;
		d[i] = a[i].S - a[i].F + 1;
	}
	double prz = 2000.0;
	for(int i=0;i<n;i++){
		int j = (i+1) % n;
		double p1 = (b[i]*prz)/d[i];
		double p2 = (b[j]*prz)/d[j];
		double p3 = (b[i]*b[j]*prz)/(d[i]*d[j]);
		double add = p1 + p2 - p3;
		ans += add;
	}
	printf("%.6lf\n",ans);
	return 0;
}
