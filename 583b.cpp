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

int a[1005],vs[1005],vs1[1005],vs2[1005];
int main(){
	int n,x=0,cnt=0,start;
	int x1=0,cnt1=0;
	int x2=0,cnt2=0;
	si(n);
	for(int i=0;i<n;i++){
		si(a[i]);
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(!vs[j]){
					if(a[j]<=x){
						x++;
						cnt++;
						vs[j]=1;
					}
				}
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				if(!vs[j]){
					if(a[j]<=x){
						x++;
						cnt++;
						vs[j]=1;
					}
				}
			}
		}
		if(cnt==n){
			dout(i);
			break;
		}
	}
	return 0;
}
