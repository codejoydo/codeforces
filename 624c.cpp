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

int g[505][505];
int n,m;
int vs[505];
int c[505];
int d[505];
queue<int> q;

inline int bfs(int ii){
    q.push(ii);
    bool fl = true;
    int cnt = 0;
    vs[ii] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(i==u) continue;
            if(!g[u][i]){
                if(u==ii) cnt++;
                int w = i;
                if(w<u){trace(w,u);}
                if(vs[w] and d[w] == d[u]){
                    fl = false;
                }
                else if(!vs[w]){
                    vs[w] = 1;
                    q.push(w);
                    d[w] = d[u] + 1;
                    c[w] = (d[w]&1) ? 2 : 0;
                }
            }
        }
        vs[u] = 2;
    }
    if(cnt==0) c[ii] = 1;
    trace(c[ii]);
    if(fl) return 1;
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) g[i][j]=0;
    for(int i=0;i<m;i++){
        int a,b;
        si(a);si(b);
        g[a][b]=1;
        g[b][a]=1;
    }
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            ans *= bfs(i);
        }
    }
    bool fg = false;
    for(int i=1;i<=n;i++){
        if(fg) break;
        for(int j=1;j<=n;j++){
            if(fg) break;
            if(g[i][j]==1 and abs(c[i]-c[j])>1){
                ans = 0;
                fg = true;
            }
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++){
            if(c[i]==2) putchar('c');
            else if(c[i]==1) putchar('b');
            else putchar('a');
        }
        cout<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}
