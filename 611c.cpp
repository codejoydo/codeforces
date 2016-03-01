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

char a[505][505];
int h[505][505];
int v[505][505];
int main(){
	int n;cin>>n;
	int m;cin>>m;
	for(int i=0;i<n;i++) scanf("%s",a[i]);
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<m-1;j++){
			if(a[i][j]=='.' and a[i][j+1]=='.') cnt++;
			h[i][j] = cnt;
			trace(i,j,h[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		int cnt = 0;
		for(int j=0;j<n-1;j++){
			if(a[j][i]=='.' and a[j+1][i]=='.') cnt++;
			v[j][i] = cnt;
			trace(j,i,v[j][i]);
		}
	}
	int q;cin>>q;
	while(q--){
		int x1;cin>>x1;x1--;
		int y1;cin>>y1;y1--;
		int x2;cin>>x2;x2--;
		int y2;cin>>y2;y2--;
		int ans = 0;
		for(int i=y1;i<=y2;i++){
			int l = x1==0 ? 0 : v[x1-1][i];
			int r = x2==0 ? 0 : v[x2-1][i];
			trace(i,r-l);
			ans += r-l;
		}
		for(int i=x1;i<=x2;i++){
			int l = y1==0 ? 0 : h[i][y1-1];
			int r = y2==0 ? 0 : h[i][y2-1];
			trace(i,r-l);
			ans += r-l;
		}
		cout<<ans<<endl;
	}
	return 0;
}
