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

II aa[100005];
pair<long double, int> d[100005];

int ck(int a,int b,int m,int n, int x, int y){
	LL s1 = (n-b)*(x-m);
	LL s2 = (y-n)*(m-a);
	if(s1==s2) return 0;
	return 1;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		si(aa[i].F);si(aa[i].S);
	}
	for(int i=1;i<n;i++){
		d[i].F = sqrt( (aa[i].F-aa[0].F)*(aa[i].F-aa[0].F) + (aa[i].S - aa[0].S)*(aa[i].S - aa[0].S) );
		d[i].S = i;
	}
	sort(d+1,d+n);
	int tp = d[1].S;
	for(int i=2;i<n;i++){
		int id = d[i].S;
		if( ck(aa[0].F, aa[0].S, aa[tp].F, aa[tp].S, aa[id].F, aa[id].S) ){
			cout<<1<<' '<<tp+1<<' '<<id+1<<endl;
			break;
		}
	}
	return 0;
}
