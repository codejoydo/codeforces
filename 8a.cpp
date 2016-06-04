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
char a[100005],b[105],c[105];
int main(){
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	int la = strlen(a);
	int lb = strlen(b);
	int lc = strlen(c);
	int f = 0, ba = 0, l;
	l = -1;
	for(int i=0;i<la-lb+1;i++){
		int fl = 1;
		for(int j=0;j<lb;j++){
			if(b[j]!=a[i+j]){
				fl = 0;
				break;
			}
		}
		if(fl){
			l = i;
			break;
		}
	}
	if(l!=-1)
	for(int i=l+lb;i<la-lc+1;i++){
		int fl = 1;
		for(int j=0;j<lc;j++){
			if(c[j]!=a[i+j]){
				fl = 0;
				break;
			}
		}
		if(fl){
			f = 1;
			break;
		}
	}
	l = -1;
	for(int i=la-1;i>=lb-1;i--){
		int fl = 1;
		for(int j=0;j<lb;j++){
			if(b[j]!=a[i-j]){
				fl = 0;
				break;
			}
		}
		if(fl){
			l = i;
			break;
		}
	}
	if(l!=-1);
	for(int i=l-lb;i>=lc-1;i--){
		int fl = 1;
		for(int j=0;j<lc;j++){
			if(c[j]!=a[i-j]){
				fl = 0;
				break;
			}
		}
		if(fl){
			ba = 1;
			break;
		}
	}
	if(!f and !ba) puts("fantasy");
	else if(!f) puts("backward");
	else if(!ba) puts("forward");
	else puts("both");

	return 0;
}
