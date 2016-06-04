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

int t[1005];
int p[1005];

int main(){
    int n,c;
    si(n);si(c);
    for(int i=0;i<n;i++){
        si(p[i]);
    }
    for(int i=0;i<n;i++){
        si(t[i]);
    }
    int a=0,b=0;
    int tim = 0;
    for(int i=0;i<n;i++){
        tim += t[i];
        int add = max(0,p[i]-tim*c);
        a += add;
    }
    tim = 0;
    for(int i=n-1;i>=0;i--){
        tim += t[i];
        int add = max(0,p[i]-tim*c);
        b += add;
    }
    if(a>b) puts("Limak");
    else if(a<b) puts("Radewoosh");
    else puts("Tie");
	return 0;
}
