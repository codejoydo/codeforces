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

int a[100005];
int b[100005];
LL c[100005];
const LL mod=1e9+7;
int x[20];
int main(){
	x[0]=1;
	for(int i=1;i<10;i++){
		x[i]=x[i-1]*10;
		trace(x[i]);
	}
	int n;si(n);
	int k;si(k);
	int l=n/k;
	for(int i=0;i<l;i++) si(a[i]);
	for(int i=0;i<l;i++) si(b[i]);
	for(int i=0;i<l;i++){
		int cnt=x[k]/a[i]+1;
		if(x[k]%a[i]==0)
			cnt--;
		int sz;
		for(int j=9;j>=0;j--){
			if(a[i]/x[j]){
				sz=j+1;
				break;
			}
		}
		trace(cnt,sz);
		if(b[i]==0){
			cnt-=x[k-1]/a[i]+1;
			if(x[k-1]%a[i]){
				cnt++;
			}
		}
		else{
			if(k==sz){
				int tp=a[i];
				trace(tp);
				int m=1;
				while(tp*m<x[sz]){
					if((tp*m)/x[sz-1]==b[i])
						cnt--;
					m++;
				}
			}
			else{
				cnt-=x[k-1]/a[i];
				if(x[k-1]%a[i] && a[i]/x[sz-1]==b[i]){
					cnt--;
				}
			}
		}
		trace(cnt);
		c[i]=cnt;
	}
	LL ans=1;
	for(int i=0;i<l;i++){
		ans=(ans*c[i])%mod;
	}
	lldout(ans);
	return 0;
}
