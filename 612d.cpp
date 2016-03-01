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

VII v;
int main(){
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		int a,b;scanf("%d%d",&a,&b);
		v.PB(MP(a,1));v.PB(MP(b,2));
	}
	sort(ALL(v));
	int cnt=0,last,sz=0;
	VII vv,vvv;
	for(int i=0;i<2*n;i++){
		if(v[i].S==1) cnt++;
		if(v[i].S==2) cnt--;
		if(cnt==k && v[i].S==1) last = v[i].F;
		if(cnt==k-1 && v[i].S==2){
			if(vv.empty()){ vv.PB(MP(last,v[i].F)); sz++; }
			else{
				if(vv[sz-1].S==last) vv[sz-1].S=v[i].F;
				else{
					vv.PB(MP(last,v[i].F));
					sz++;
				}
			}
		}
		//trace(v[i].F,v[i].S,last,cnt);
	}
	cout<<(int)SZ(vv)<<endl;
	for(int i=0;i<SZ(vv);i++){
		cout << vv[i].F << ' ' << vv[i].S << endl;
	}
	return 0;
}
