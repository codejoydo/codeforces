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

LL a[505][505],v[505],vs[505],ans[505];

int main(){
  int n;
  si(n);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) sll(a[i][j]);
  for(int i=1;i<=n;i++) sll(v[i]);
  for(int k=n;k>=1;k--){
    LL sum = 0;
    int kk = v[k];
    vs[kk] = 1;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++){
        if(vs[i] and vs[j]){
          a[i][kk] = min(a[i][kk], a[i][j]+a[j][kk]);
          a[kk][i] = min(a[kk][i], a[kk][j]+a[j][i]);
        }
      }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++){
        if(vs[i] and vs[j]){
          a[i][j] = min(a[i][j], a[i][kk]+a[kk][j]);
        }
      }
    for(int j=1;j<=n;j++)
      for(int i=1;i<=n;i++){
        if(vs[i] and vs[j])
        sum += a[i][j];
      }
    ans[k] = sum;      
  }
  for(int i=1;i<=n;i++) cout<<ans[i]<<' '; cout<<endl;
	return 0;
}
