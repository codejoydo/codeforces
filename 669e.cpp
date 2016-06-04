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
const int N = 100005;
vector< pair< int, II > > Q;
VI BIT[N];
map<int,int> mp,mpos[N];
set<int> pos[N];
inline void update(int t,int x,int add){
	for(x;x<SZ(BIT[t]);x+=(x^(x&(x-1))))
		BIT[t][x]+=add;
}
inline int query(int t,int x){ 
	int ret=0;
	for(x;x;x=(x&(x-1)))
		ret+=BIT[t][x];
	return ret;
}
int main(){
	int n;
	si(n);
	for(int i=0;i<n;i++){
		int a,b,c;
		si(a);si(b);si(c);
		mp[c];
		Q.PB({a,{b,c}});
	}
	int cnt = 0;
	for(auto it=mp.begin();it!=mp.end();it++)
		it->S = cnt++;
	for(int i=0;i<n;i++){
		int a = Q[i].F, b = Q[i].S.F, c = mp[Q[i].S.S];
		//trace(a,b,c);
		pos[c].insert(b);
	}
	for(int i=0;i<cnt;i++){
		BIT[i].resize(SZ(pos[i])+5);
		int tp = 1;
		for(auto j=pos[i].begin();j!=pos[i].end();j++){
			//trace(i,*j);
			mpos[i][*j] = tp++;
		}
	}
	//trace("done");
	for(int i=0;i<n;i++){
		int a = Q[i].F, c = mp[Q[i].S.S];
		int b = mpos[c][Q[i].S.F];
		//trace(a,b,c);
		if(a==1){
			update(c,b,1);
		}
		else if(a==2){
			update(c,b,-1);
		}
		else if(a==3){
			dout(query(c,b)-query(c,0));
		}
	}
	return 0;
}
