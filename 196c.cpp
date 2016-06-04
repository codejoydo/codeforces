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

VI g[2000];
pair<II,int> v[2000];
int vs[2000],cnt[2000],ans[2000];
int n;

bool cmp(const pair<II,int> &a,const pair<II,int> &b){
    LL x1 = a.first.first, y1 = a.first.second;
    LL x2 = b.first.first, y2 = b.first.second;
    return (x1*y2 - x2*y1) > 0;
}

int dfs(int u){
    vs[u] = 1;
    int tp = 1;
    for(int i=0;i<SZ(g[u]);i++){
        int w = g[u][i];
        if(!vs[w]) tp+=dfs(w);
    }
    return cnt[u] = tp;
}

void foo(int u,int l,int r){
    for(int i=l+1;i<=r;i++) if(v[l]>v[i]) swap(v[l],v[i]);
    ans[v[l].S] = u;
    vs[u] = 1;
    for(int i=l+1;i<=r;i++){
        v[i].F.F -= v[l].F.F;
        v[i].F.S -= v[l].F.S;
    }
    sort(v+l+1,v+r+1,cmp);
    for(int i=l+1;i<=r;i++){
        v[i].F.F += v[l].F.F;
        v[i].F.S += v[l].F.S;
    }
    int curr = l+1;
    for(int i=0;i<SZ(g[u]);i++){
        int w = g[u][i];
        if(!vs[w]){
            foo(w,curr,curr+cnt[w]-1);
            curr += cnt[w];
        }
    }
}

void solve(){
    dfs(1);
    SET(vs,0);
    foo(1,1,n);
}

int main(){
    si(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        si(a);si(b);
        g[a].PB(b);
        g[b].PB(a);
    }
    for(int i=1;i<=n;i++){
        int a,b;
        si(a);si(b);
        v[i] = MP(MP(a,b),i);
    }
    solve();
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}
