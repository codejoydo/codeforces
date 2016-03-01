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

VI g[3005];
int vs[3005],p[3003],d[3003],m[3003];
VI v;

void dfs(int u,int l){
  vs[u] = 1;
  d[u] = l;
  v.PB(u);
  for(int i=0;i<SZ(g[u]);i++){
    int w = g[u][i];
    if(!vs[w]){
      p[w] = u;
      dfs(w,l+1);
    }
    else{
      if(w!=p[u]){
       for(int j=d[w];j<SZ(v);j++){
         m[v[j]] = 1;
       }
      }
    }
  }
  v.pop_back();
}

int mn;

void dfs1(int u,int l){
  vs[u] = 1;
  if(m[u]) mn = min(l,mn);
  for(int i=0;i<SZ(g[u]);i++){
    int w = g[u][i];
    if(!vs[w]) dfs1(w,l+1);
  }
}

int main(){
  int n;
  si(n);
  for(int i=0;i<n;i++){
    int a,b;
    si(a);si(b);
    g[a].PB(b);
    g[b].PB(a);
  }
  dfs(1,0); 
  for(int i=1;i<=n;i++){
    SET(vs,0);
    mn = 100005;
    dfs1(i,0);
    cout<<mn<<' ';
  }
  cout<<endl;
	return 0;
}
