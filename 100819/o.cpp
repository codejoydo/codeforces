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
string a[505];
int val[505][505];
int vs[505][505];
int n,m;
int dfs(int i,int j){
	queue<II> q;
	vs[i][j] = 1;
	q.push({i,j});
	while(!q.empty()){
		int x = q.front().F;
		int y = q.front().S;
		//trace(x,y);
		q.pop();
		int v = a[x][y] - '0';
		if(x-v>=0){
			if(!vs[x-v][y]){
				q.push({x-v,y});
				vs[x-v][y] = 1;
				val[x-v][y] = val[x][y]+1;
				if(x-v==n-1 and y==m-1) return val[x-v][y];
			}
		}
		if(y-v>=0){
			if(!vs[x][y-v]){
				q.push({x,y-v});
				vs[x][y-v] = 1;
				val[x][y-v] = val[x][y]+1;
				if(x==n-1 and y-v==m-1) return val[x][y-v];
			}
		}
		if(x+v<n){
			if(!vs[x+v][y]){
				q.push({x+v,y});
				vs[x+v][y] = 1;
				val[x+v][y] = val[x][y]+1;
				if(x+v==n-1 and y==m-1) return val[x+v][y];
			}
		}
		if(y+v<m){
			if(!vs[x][y+v]){
				q.push({x,y+v});
				vs[x][y+v] = 1;
				val[x][y+v] = val[x][y]+1;
				if(x==n-1 and y+v==m-1) return val[x][y+v];
			}
		}
	}
	return -1;
}
int main(){
	si(n);si(m);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans = dfs(0,0);
	if(ans == -1) puts("IMPOSSIBLE");
	else dout(ans);
	return 0;
}
