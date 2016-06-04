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
const LL MOD = 51123987;
const int N = 2000006;
char s[N];
LL start[N],finish[N],total;
VI l;
int main(){
	int n;
	si(n);
	scanf("%s",s);
	int i = 0;
	int palLen = 0;
	l.clear();
	while(i < n){
		if(i > palLen and s[i-palLen-1] == s[i]){
			palLen += 2;
			i++;
			continue;
		}
		l.PB(palLen);
		int s = SZ(l) - 2;
		int e = s - palLen;
		int fl = 0;
		for(int j=s;j>e;j--){
			int d = j - e - 1;
			if(l[j] == d){
				palLen = d;
				fl = 1; // ***
				break;
			}
			l.PB(min(d,l[j]));
		}
		if(!fl){
			palLen = 1;
			i++;
		}
	}
	l.PB(palLen);
	int s = SZ(l) - 2;
	int e = s - (2*n + 1 - SZ(l));
	for(int i=s;i>e;i--){
		int d = i - e - 1;
		l.PB(min(d,l[i]));
	}
	for(int i=0;i<SZ(l);i++){
		if(!i) continue;
		if(i==SZ(l)-1) continue;
		if(i&1){
			total += (l[i]+1)/2;
			start[i/2 - l[i]/2] += 1;
			finish[i/2 + l[i]/2] += 1;
		   	start[i/2+1] -= 1;
			finish[i/2-1] -= 1;
		}
		else{
			total += l[i]/2;
			start[i/2 - l[i]/2] += 1;
			finish[i/2 - 1 + l[i]/2] += 1;
		   	start[i/2] -= 1;
			finish[i/2-1] -= 1;
		}
		total %= MOD;
	}
	for(int i=1;i<n;i++){
		start[i] += start[i-1];
		start[i] %= MOD;
	}
	for(int i=n-2;i>=0;i--){
		finish[i] += finish[i+1];
		finish[i] %= MOD;
	}
	for(int i=1;i<n;i++){
		finish[i] += finish[i-1];
		finish[i] %= MOD;
	}
	LL sub = 0;
	LL ans = ((total*(total-1))/2) % MOD;
	for(int i=1;i<n;i++){
		sub += (start[i] * finish[i-1]) % MOD;
		sub %= MOD;
	}
	ans -= sub;
	ans += MOD;
	ans %= MOD;
	lldout(ans);
	trace(total);
	return 0;
}
