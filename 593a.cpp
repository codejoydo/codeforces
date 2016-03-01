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

char a[1005];
int c[30][30];
set<int> s;
int main(){
	int n;
	si(n);
	for(int i=0;i<n;i++){
		s.clear();
		scanf("%s",a);
		int l=strlen(a);
		for(int j=0;j<l;j++){
			s.insert(a[j]-'a');
		}
		if(SZ(s)==2){
			auto it=s.begin();
			int x=*it;it++;
			int y=*it;
			c[x][y]+=l;
			c[y][x]+=l;
			trace(i,l);
		}
		else if(SZ(s)==1){
			auto it=s.begin();
			int x=*it;
			trace(i,l);
			for(int k=0;k<26;k++){
				c[x][k]+=l;
				if(k!=x)c[k][x]+=l;
			}
		}
	}
	int mx=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			mx=max(c[i][j],mx);
		}
	}
	dout(mx);
	return 0;
}
