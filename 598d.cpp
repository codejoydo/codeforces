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

char a[1005][1005];
int vs[1005][1005];
int mk[1000006];
int cmpno=1,cnt;
int n,m,q;

void dfs(int ii,int jj){
	vs[ii][jj]=cmpno;
	if(a[ii][jj]=='*')
		return;
	trace(ii+1,jj+1);
	if(a[max(ii-1,0)][jj]=='*')
		cnt++;
	if(a[ii][max(jj-1,0)]=='*')
		cnt++;
	if(a[min(ii+1,n-1)][jj]=='*')
		cnt++;
	if(a[ii][min(jj+1,m-1)]=='*')
		cnt++;

	if(!vs[max(ii-1,0)][jj]) dfs(max(ii-1,0),jj);
	if(!vs[ii][max(jj-1,0)]) dfs(ii,max(jj-1,0));
	if(!vs[min(ii+1,n-1)][jj]) dfs(min(ii+1,n-1),jj);
	if(!vs[ii][min(jj+1,m-1)]) dfs(ii,min(jj+1,m-1));
}	

int main(){
	si(n);
	si(m);
	si(q);
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vs[i][j] && a[i][j]=='.'){
				trace(i,j);
				cnt=0;
				dfs(i,j);
				mk[cmpno++]=cnt;
			}
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		si(a);a--;
		si(b);b--;
		cmpno=vs[a][b];
		dout(mk[cmpno]);
	}
	return 0;
}
