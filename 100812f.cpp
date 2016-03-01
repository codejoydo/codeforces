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

int c[100005];
int pc[100005];
int ps[100005];
char * a[100005];
int main(){
	int n,m;
	si(n);si(m);
	for(int i=0;i<n;i++)
		a[i]=(char *)malloc((m+5)*sizeof(char));
	for(int i=0;i<n;i++)
		scanf("%s",a[i]);
	int onecnt=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<m;j++){
			if(a[i][j]=='+'){
				c[cnt]++;
				cnt=0;
			}
			else{
				onecnt++;
				cnt++;
			}
		}
		c[cnt]++;
	}

	for(int j=0;j<m;j++){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i][j]=='+'){
				c[cnt]++;
				cnt=0;
			}
			else{
				cnt++;
			}
		}
		c[cnt]++;
	}

	int l=max(m,n);
	for(int i=l;i>=1;i--){
		ps[i]=c[i]*i+ps[i+1];
		pc[i]=c[i]+pc[i+1];
	}
	cout << onecnt << ' ';
	for(int i=2;i<=l;i++){
		int ans=ps[i]-(i-1)*pc[i];
		printf("%d ",ans);
	}
	cout << endl;
	return 0;
}
