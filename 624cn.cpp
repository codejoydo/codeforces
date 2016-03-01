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

int d[505];
int g[505][505];
char ans[505];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        d[a]++;
        d[b]++;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int a,cb=0,c;
    set<int> s;
    for(int i=1;i<=n;i++) if(d[i]==n-1) cb++;
    for(int i=1;i<=n;i++) if(d[i]!=n-1) s.insert(d[i]);
    if(s.empty()){
        for(int i=1;i<=n;i++) ans[i]='b';
    }
    else if(SZ(s)==1){
        int cnt = n - cb;
        if(cnt&1){
            cout<<"No"<<endl;
            return 0;
        }
        cnt/=2;
        for(int i=1;i<=n;i++){
            if(d[i]==n-1) ans[i]='b';
            else{
                if(cnt){
                    ans[i]='a';
                    cnt--;
                }
                else ans[i]='c';
            }
        }
    }
    else if(SZ(s)==2){
        auto it = s.begin();
        a = *it;
        it++;
        c = *it;
        for(int i=1;i<=n;i++){
            if(d[i]==n-1) ans[i]='b';
            else if(d[i]==a) ans[i]='a';
            else if(d[i]==c) ans[i]='c';
        }
    }
    else{
        cout<<"No"<<endl;
        return 0;
    }
    bool fl = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]){
                if(abs(ans[i]-ans[j])>1) fl = false;
            }
            /*else{
                if(abs(ans[i]-ans[j])<2) fl = false;
            }*/
        }
    } 
    if(1){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
            putchar(ans[i]);
        cout<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
