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

int a[200005],b[200005],c[200005],d[200005];
stack<II> s;
VII v;
int main(){
    int n,m;
    si(n);si(m);
    for(int i=0;i<n;i++) si(a[i]);
    for(int i=0;i<m;i++){ si(d[i]); si(b[i]); }
    for(int i=0;i<m;i++){
        if(s.empty()){
            s.push(MP(b[i],d[i]));
            continue;
        }
        if(s.top().F <= b[i]){
            while(1){
               if(s.empty()) break;
               else if(s.top().F <= b[i]) s.pop();
               else break;
            }
            if(s.empty()) s.push(MP(b[i],d[i]));
            else if(s.top().S != d[i]) s.push(MP(b[i],d[i]));
            else continue;
        }
        else if(s.top().S != d[i]) s.push(MP(b[i],d[i]));
        else continue;
    }
    while(!s.empty()){
        v.PB(s.top());
        s.pop();
    }
    //printing the order
    int l,r,end,endd;
    II tp = v.back();
	end = tp.F,l = 0, r = tp.F-1;
    endd = end;
    if(tp.S == '1'){
        for(int i=0;i<end;i++) c[i] = i;
    }
    else{
        for(int i=0;i<end;i++) c[i] = end - 1 - i;
    }
    for(int i=end;i<n;i++) c[i] = a[i];
    for(int i=SZ(v)-2;i>=0;i--){
        if(v[i].S == 2){
			int start = v[i].F+l;
			r = start-1;
			for(int j=v[i].F;j<end;j++){
				c[j] = start;
				start++;
			}
			end = v[i].F;
		}
		else{
			int start = r-v[i].F;
            l = start+1;
            for(int j=v[i].F;j<end;j++){
                c[j] = start;
                start--;
            }
		    end = v[i].F;
        }
    }
    if(v[0].S == 2){
        int start = r;
        for(int i=0;i<end;i++){
            c[i] = start;
            start--;
        }
    }
    else{
        int start = l;
        for(int i=0;i<end;i++){
            c[i] = start;
            start++;
        }
    }
    sort(a,a+endd);
    for(int i=0;i<endd;i++) c[i] = a[c[i]];    
    for(int i=0;i<n;i++) cout<<c[i]<<' '; cout<<endl;
	return 0;
}
