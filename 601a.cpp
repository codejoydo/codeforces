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

int k;
int vs[500],d[500];
int g[500][500];

int n,m;

int bfs(int u){
  queue<int> q;
  q.push(u);
  vs[u] = 1;
  d[u] = 0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i=1;i<=n;i++){
      int w = g[v][i];
      if(!vs[i] and w==k){
        vs[i] = 1;
        q.push(i);
        d[i] = d[v] + 1;
      }
    }
  }
  return d[n];
}

int main(){
  si(n);si(m);
  for(int i=0;i<m;i++){
    int a,b;
    si(a);si(b);
    g[a][b] = 1;
    g[b][a] = 1;
  }
  k = g[1][n] ? 0 : 1;
  int ans = bfs(1); 
  if(vs[n]) dout(ans);
  else puts("-1");
	return 0;
}
