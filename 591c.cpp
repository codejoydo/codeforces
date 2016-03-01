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

int a[500005],b[500005],c[500005];
int main(){
	int n;
	si(n);
	for(int i=0;i<n;i++) si(a[i]);
	int cnt=0,mx=0,start;
	b[0]=a[0];
	for(int i=1;i<n-1;i++){
		if(a[i]==a[i-1] || a[i]==a[i+1]){
			b[i]=a[i];	
			if(cnt){
				c[start]=cnt;
			}
			//trace(cnt);
			mx=max(mx,(cnt+1)/2);
			cnt=0;
			continue;
		}
		else{
			if(cnt==0)
				start=i;
			cnt++;
		}
	}	
	b[n-1]=a[n-1];
	if(cnt){
		c[start]=cnt;
	}
	mx=max(mx,(cnt+1)/2);
	dout(mx);
	for(int i=0;i<n;i++){
		if(c[i]){
			if(c[i]&1){
				int l=i+c[i],fl=b[i-1];
				for(;i<l;i++) b[i]=fl;
			}
			else{
				int base=c[i];
				int l=i+base/2,fl=b[i-1],rl=1-fl;
				for(;i<l;i++) b[i]=fl;		
				l=i+base/2;
				for(;i<l;i++) b[i]=rl;
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",b[i]);
	cout << endl;	

	return 0;
}
