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
const int N = 100005;
LL a[N],b[N];
typedef vector<pair<LL,LL>> VLL;
VLL w,v;
int main(){
	LL n,k;
	sll(n);sll(k);
	for(int i=0;i<n;i++) sll(a[i]);
	for(int i=0;i<n;i++) sll(b[i]);
	for(int i=0;i<n;i++) v.PB({b[i]/a[i],i});
	sort(ALL(v));
	for(int i=0;i<n;i++){
		int j = v[i].S;
		if(w.empty()){
			w.PB(MP(b[j],a[j]));
			continue;
		}
		LL aa = w[SZ(w)-1].F;
		LL bb = w[SZ(w)-1].S;
		if(v[i].F!=aa/bb){
			w.PB(MP(b[j],a[j]));
		}
		else{
			w[SZ(w)-1].F += b[j];
		   	w[SZ(w)-1].S += a[j];
		}
	}
	LL mn = w[0].F / w[0].S;
	for(int i=0;i<SZ(w);i++){
		if(!k) break;
		if(i){
			w[i].F += w[i-1].F;
			w[i].S += w[i-1].S;
		}
		LL l1 = w[i].F / w[i].S;
		LL l2 = w[i+1].F / w[i+1].S;
		int add = min(k,l2*(w[i].S)-w[i].F);
		w[i].F += add;
		mn += (w[i].F) / w[i].S - l1;
		k -= add;
	}
	if(k)
	{
		int i = SZ(w) - 1;
		LL l1 = w[i].F / w[i].S;
		mn += (w[i].F+k) / w[i].S - l1;
	}
	cout<<mn<<endl;
	return 0;
}
