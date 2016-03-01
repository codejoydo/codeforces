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

int t[200005];
vector< pair< LL,int > > a;
int main(){
	int n;si(n);
	int m;si(m);
	int k;si(k);
	int s;si(s);
	LL dmin = 1e9+1,dday;
	LL pmin = 1e9+1,pday;
	for(int i=1;i<=n;i++){
		int tp;si(tp);
		if(tp<dmin){
			dmin = tp;
			dday = i;
		}
	}
	for(int i=1;i<=n;i++){
		int tp;si(tp);
		if(tp<pmin){
			pmin = tp;
			pday = i;
		}
	}
	for(int i=1;i<=m;i++){
		int c;si(t[i]);si(c);
		pair< LL,int> p;
		p.S = i;
		if(t[i]==1) p.F = (LL)dmin*(LL)c;
		else p.F = (LL)pmin*(LL)c;
		a.PB(p);
	}
	sort(ALL(a));
	LL sum = 0;
	for(int i=0;i<k;i++){
		sum += a[i].F;
	}
	if(sum>s) cout << -1 << endl;
	else{
		cout << max(pday,dday) << endl;
		for(int i=0;i<k;i++){
			cout << a[i].S << ' ';
			if(t[a[i].S]==1) cout << dday << endl;
			else cout << pday << endl;
		}
	}
	return 0;
}
