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
int a[101][101],b[101][101];
int n,m,k;
int pos[16] = {1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1};
int f(int x,int y){
	int ret = a[x][y];
	for(int i=0;i<16;i+=2){
		int j = i+1;
		int xx = (x + pos[i] + n) % n;
		int yy = (y + pos[j] + m) % m;
		ret += a[xx][yy];
	}
	return ret;
}
set<int> s;	
int main(){
	si(m);si(n);si(k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			si(a[i][j]);
	for(int t=0;t<k;t++){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				b[i][j] = f(i,j);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j] = b[i][j];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			s.insert(a[i][j]);
	dout(SZ(s));
	return 0;
}
