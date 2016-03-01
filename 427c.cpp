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

VI v;
int vs[100005],a[100005];
VI g[100005],gg[100005];
LL mn,cnt;
const LL MOD = 1e9+7;

void dfs(int u){
  vs[u] = 1;
  for(int i=0;i<SZ(g[u]);i++){
    int w = g[u][i];
    if(!vs[w]) dfs(w);
  }
  v.PB(u);
}

void dfs1(int u){
  vs[u] = 1;
  if(mn > a[u]){ cnt = 1; mn = a[u]; }
  else if(mn == a[u]) cnt++;
  for(int i=0;i<SZ(gg[u]);i++){
    int w = gg[u][i];
    if(!vs[w]) dfs1(w);
  }
}

int main(){
  int n,m;
  si(n);
  for(int i=1;i<=n;i++) si(a[i]);
  si(m);  
  for(int i=0;i<m;i++){
    int a,b;
    si(a);si(b);
    g[a].PB(b);
    gg[b].PB(a);
  }
  for(int i=1;i<=n;i++) if(!vs[i]) dfs(i);
  SET(vs,0);
  LL ans = 0, way = 1;
  for(int i=n-1;i>-1;i--){
    int u = v[i];
    if(!vs[u]){
      mn = 1e9+7;
      cnt = 1;
      dfs1(u);
      ans += mn;
      way *= cnt;
      way %= MOD;
    }
  }
  printf("%lld %lld\n",ans,way);
  return 0;
}
