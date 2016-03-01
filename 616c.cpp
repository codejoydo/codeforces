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

string a[1005];
int vs[1005][1005],b[1000006];
int n,m,mark,cmpno;

int dfs(int i,int j){
	int cnt = 1,p,q;
	vs[i][j] = cmpno;
	p = min(i+1,n-1), q = j;
	if(!vs[p][q] and a[p][q] == '.') cnt += dfs(p,q);
	p = i, q = min(j+1,m-1);
	if(!vs[p][q] and a[p][q] == '.') cnt += dfs(p,q);
	p = max(i-1,0), q = j;
	if(!vs[p][q] and a[p][q] == '.') cnt += dfs(p,q);
	p = i, q = max(j-1,0);
	if(!vs[p][q] and a[p][q] == '.') cnt += dfs(p,q);
	return cnt;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] == '.' and !vs[i][j]){
				cmpno++;
				b[cmpno] = dfs(i,j);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] == '*'){
				int p,q,cnt = 1;
				set<int> s;
				p = min(i+1,n-1), q = j;
				if(a[p][q] == '.') s.insert(vs[p][q]);
				p = i, q = min(j+1,m-1);
				if(a[p][q] == '.') s.insert(vs[p][q]);
				p = max(i-1,0), q = j;
				if(a[p][q] == '.') s.insert(vs[p][q]);
				p = i, q = max(j-1,0);
				if(a[p][q] == '.') s.insert(vs[p][q]);
				for(auto it=s.begin();it!=s.end();++it) cnt += b[*it];
				cout<<cnt%10;
			}
			else cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
