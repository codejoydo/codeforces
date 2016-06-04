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

VII sa;
int n,m;
map<int,int> sz,rt,ii,jj;
int a[1005][1005];
int b[1005][1005];
int vs[1005][1005];
int p[1000006];
int cap[1000006];

int root(int x){return p[x]==x ? x : (p[x] = root(p[x]));}
void merge(int x,int y){
    if((x = root(x)) == (y = root(y)))     return ;
    cap[x] += cap[y];
    p[y] = x;
}
int ct,lim,mark,ansrt;
void dfs(int x,int y){
    if(vs[x][y]) return;
    if(ct==lim) return;
    vs[x][y] = 1;
    ct++;
    trace(x,y,ct);
    b[x][y] = mark;
    if(root(m*x+min(y+1,m-1)) == root(m*x+y)) dfs(x,min(y+1,m-1));
    if(root(m*max(x-1,0)+y) == root(m*x+y)) dfs(max(x-1,0),y);
    if(root(m*x+max(y-1,0)) == root(m*x+y)) dfs(x,max(y-1,0));
    if(root(m*min(x+1,n-1)+y) == root(m*x+y)) dfs(min(x+1,n-1),y);
}
int main(){
    LL k;
    si(n);si(m);sll(k);
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            si(a[i][j]);
            p[cnt] = cnt;
            cap[cnt] = 1;
            sa.PB(MP(a[i][j],cnt));
            cnt++;
        }
    }
    sort(ALL(sa));
    reverse(ALL(sa));
    int ansv = -1;
    int ansi,ansj;
    for(int i=0;i<n*m;i++){
        int j = i;
        while(sa[j].F==sa[i].F){
            int x = sa[j].S / m;
            int y = sa[j].S % m;
            if(a[max(x-1,0)][y] >= a[x][y]) merge(m*max(x-1,0)+y,m*x+y);
            if(a[x][max(y-1,0)] >= a[x][y]) merge(m*x+max(y-1,0),m*x+y);
            if(a[min(x+1,n-1)][y] >= a[x][y]) merge(m*min(x+1,n-1)+y,m*x+y);
            if(a[x][min(y+1,m-1)] >= a[x][y]) merge(m*x+min(y+1,m-1),m*x+y);
            if(sz[sa[j].F]<cap[root(m*x+y)]){
                sz[sa[j].F] = cap[root(m*x+y)];
                rt[sa[j].F] = root(m*x+y);
                ii[sa[j].F] = x;
                jj[sa[j].F] = y;
            }
            if(sa[i].F==sa[j+1].F) j++;
            else break;
        }
        i=j;
        if(k%sa[i].F==0 and k/sa[i].F<=sz[sa[i].F]){
            ansv = sa[i].F;
            ansi = ii[ansv];
            ansj = jj[ansv];
            ansrt = rt[ansv];
            break;
        }
    }
    if(ansv==-1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        ct = 0,lim=k/ansv, mark = ansv;
        trace(lim);
        dfs(ansi,ansj);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout<<b[i][j]<<' '; cout<<endl;
        }
    }
    return 0;
}
