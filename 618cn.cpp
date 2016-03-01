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

pair<pair<LL,LL>,int> aa[100005];

int ck(LL a,LL b,LL m,LL n, LL x, LL y){
	LL s1 = (n-b)*(x-m);
	LL s2 = (y-n)*(m-a);
	if(s1==s2) return 0;
	return 1;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		sll(aa[i].F.F);sll(aa[i].F.S);
		aa[i].S = i+1;
	}
	sort(aa,aa+n);
	sort(aa+1,aa+n);
	for(int i=2;i<n;i++){
		if( ck(aa[i].F.F, aa[i].F.S, aa[i-1].F.F, aa[i-1].F.S, aa[i-2].F.F, aa[i-2].F.S) ){
			cout<<aa[i].S<<' '<<aa[i-1].S<<' '<<aa[i-2].S<<endl;
			break;
		}
	}
	return 0;
}
