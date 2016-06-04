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

int add[300005],sub[300005],ma,ms;
int a[200005];

int main(){
    int n,k;
    si(n);si(k);
    for(int i=0;i<n+1;i++) si(a[i]);
    for(int i=0;i<n+1;i++){
        if(a[i]>0){
            int tp = a[i];
            VI v;
            while(tp){
                v.PB(tp&1);
                tp/=2;
            }
            //for(int j=0;j<SZ(v);j++) cout<<v[j]<<' '; cout<<endl;
            for(int j=i;j<i+SZ(v);j++){
                ma = max(j,ma);
                add[j] += v[j-i];
                add[j+1] += add[j]/2;
                add[j] = add[j]&1;
            }
        }
        else{
            int tp = -a[i];
            VI v;
            while(tp){
                v.PB(tp&1);
                tp/=2;
            }
            //for(int j=0;j<SZ(v);j++) cout<<v[j]<<' '; cout<<endl;
            for(int j=i;j<i+SZ(v);j++){
                ms = max(j,ms);
                sub[j] += v[j-i];
                sub[j+1] += sub[j]/2;
                sub[j] = sub[j]&1;
            }
        }
    }
    int len1 = 0, len2 =0;
    for(int j=0;j<ma+33;j++){
        if(add[j]>1){
            add[j+1] += add[j]/2;
            add[j] = add[j]&1;
        }
        if(add[j]) len1 = max(len1,j);
        cout<<add[j]<<' ';
    }
    cout<<endl;
    for(int j=0;j<ms+33;j++){
        if(sub[j]>1){
            sub[j+1] += sub[j]/2;
            sub[j] = sub[j]&1;
        }
        if(sub[j]) len2 = max(len2,j);
        cout<<sub[j]<<' ';
    }
    trace(len1,len2);
    int len = max(len1,len2);
    cout<<endl;
    for(int i=0;i<=len+1;i++){
       if(sub[i] == 0){
          sub[i] = 1;
       }
       else{
          sub[i] = 0;
       }
    }
    sub[0] += 1; 
    for(int j=0;j<=len+1;j++){
        if(sub[j]>1){
            sub[j+1] += sub[j]/2;
            sub[j] = sub[j]&1;
        }
    }
    for(int j=0;j<=len+1;j++){
        add[j] += sub[j];
        if(add[j]>1){
            add[j+1] += add[j]/2;
            add[j] = add[j]&1;
        }
    }
    if(add[len]){
	return 0;
}
