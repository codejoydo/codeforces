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
set<int> p,q;
int mk[N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b){
			p.insert(a);
			q.insert(b);
		}
		else{
			p.insert(b);
			q.insert(a);
		}
	}
	for(auto it=p.begin();it!=p.end();it++){
		mk[*it]++;
	}	   
	for(auto it=q.begin();it!=q.end();it++){
		mk[*it]++;
	}
	for(int i=1;i<n;i++){
		if(mk[i] == 2){
			dout(0);
			return 0;
		}
	}
	if(!p.empty() and !q.empty()){
		if(*(p.begin())<=*(q.rbegin())){
			dout(0);
			return 0;
		}
	}
	int cnt = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(!mk[i]){
			cnt++;
			if(!p.empty() and !q.empty())
			if(*(p.begin())>i and i>*(q.rbegin()))
				ans++;
		}
	}
	if(p.empty() and q.empty()){
		dout(cnt-1);
	}
	else{
		dout(ans+1);
	}
	return 0;
}
