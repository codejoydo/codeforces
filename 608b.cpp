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

char a[200005];
char b[200005];
int main(){
	cin>>a>>b;
	int n = strlen(a);
	int m = strlen(b);
	int diff = m - n + 1;
	int sum0 = 0;
	int sum1 = 0;
	for(int i=0;i<diff;i++){
		int x = b[i] - '0';
		if(x) sum0++;
		else sum1++;
	}
	LL sum = (a[0] == '1') ? sum1 : sum0;
	for(int i=diff;i<m;i++){
		int x = b[i] - '0';
		int y = b[i-diff] - '0';
		if(x) sum0++;
		else sum1++;
		if(y) sum0--;
		else sum1--;
		//trace(i,sum0,sum1);
		sum += (a[i-diff+1] == '1') ? sum1 : sum0;
	}
	lldout(sum);
	return 0;
}
