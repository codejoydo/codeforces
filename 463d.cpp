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

VI g[1005];
int m[10][1005];
int vs[1005],mx;
int d[1005];
int ans;

void dfs(int u, int l){
  vs[u] = 1;
  for(int i=0;i<SZ(g[u]);i++){
    int w = g[u][i];
    if(!vs[w]){
      dfs(w,l+1);
    }
    d[u] = max(d[u],d[w]+1);
  }
  d[u] = max(d[u],1);
  ans = max(d[u],ans);
}

int main(){
  int n,k;
  si(n);si(k);
  for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
      int a;
      si(a);
      m[i][a] = j;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      bool fl = true;
      for(int p=1;p<=k;p++){
        if(m[p][i]>=m[p][j]) fl = false;
      }
      if(fl){
        g[i].PB(j);
      }
    }
  }
  for(int i=1;i<=n;i++){
    SET(vs,0);
    dfs(i,1);
  }
  dout(ans);
  return 0;
}
