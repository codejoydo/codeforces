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

int n;
int vs[100005];
VI g[100005];
II e[100005];
double m[100005];
double tot;
LL wt[100005];

int adj(int i,int a){
  if(e[i].F==a) return e[i].S;
  return e[i].F;
}

LL dfs(int u){
  vs[u] = 1;
  LL cnt = 1;
  for(int i=0;i<SZ(g[u]);i++){
    int k = g[u][i];
    int w = adj(k,u);
    if(!vs[w]){
      LL tp = dfs(w);
      LL tp1 = n - tp;
      m[k] = 6;
      m[k] /= (double) n;
      m[k] *= (double) tp;
      m[k] /= (double) (n-1);
      m[k] *= (double) tp1;
      assert(m[k]>=0);
      cnt+=tp;
    }
  }
  return cnt;
}

int main(){
  si(n);
  for(int i=0;i<n-1;i++){
    int a,b,c;
    si(a);si(b);si(c);
    g[a].PB(i);
    g[b].PB(i);
    e[i] = MP(a,b);
    wt[i] = 1LL*c;
  }

  dfs(1);
  double sum = 0;
  for(int i=0;i<n-1;i++){
    sum += wt[i] * m[i];
  }

  int q;
  si(q);
  for(int i=0;i<q;i++){
    LL k,l;
    sll(k);sll(l);k--;
    LL dec = wt[k] - l;
    wt[k] = l;
    sum -= dec * m[k];
    printf("%.14lf\n",sum);
  }
	return 0;
}
