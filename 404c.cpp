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

int d[100005];
VI m[100005];
VII e;

int main(){
  int n,k;
  si(n);si(k);
  for(int i=0;i<n;i++){
    int a;
    si(a);
    m[a].PB(i+1);
  }
  if(SZ(m[0])>1){
    puts("-1");
    return 0;
  }
  int level = 1;
  while(1){
    int j = 0, size = SZ(m[level-1]);
    if(size == 0){
      puts("-1");
      return 0;
    }
    for(int i=0;i<SZ(m[level]);i++){
      if(d[m[level-1][j]] == k){
        puts("-1");
        return 0;
      }
      d[m[level-1][j]]++;
      d[m[level][i]]++;
      e.PB(MP(m[level-1][j],m[level][i]));
      if(SZ(e) == n-1){
        dout(n-1);
        for(int i=0;i<n-1;i++) printf("%d %d\n",e[i].F,e[i].S);        
        return 0;
      }
      j = (j+1) % size;
    }
    level++;
  }
  puts("-1");
	return 0;
}
