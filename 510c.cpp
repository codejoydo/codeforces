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

string a[105];
VI g[30];
int vs[30],in[30],out[30],t,cycle,id[30];
VI ans;

void dfs(int u){
//	trace(u);
	vs[u]=1;
	in[u]=t++;
	for(int i=0;i<SZ(g[u]);i++){
		int w = g[u][i];
		if(!vs[w])
			dfs(w);
		else
			if(in[w]<=in[u] && !out[w]){
				trace(w);
				cycle=1;
			}
	}
	out[u]=t++;
	ans.PB(u);
}

int main()
{
	cycle = 0;
	int n;
	si(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++){
		int l=min(a[i].length(),a[i+1].length());
		int x=0;
		for(int j=0;j<l;j++){
			if(a[i][j]!=a[i+1][j]){
				g[a[i][j]-'a'].PB(a[i+1][j]-'a');
				id[a[i+1][j]-'a']++;
				x=1;
				break;
			}
		}
		if(!x && a[i].length()>a[i+1].length())
			cycle=1;
	}
	t = 1;
	for(int i=0;i<26;i++){
		if(!vs[i] && !id[i]){
			dfs(i);
		}
	}
	for(int i=0;i<26;i++){
		if(!vs[i]){
			cycle=1;
			break;
		}
	}
	if(cycle)
		cout << "Impossible" << endl;
	else{
		reverse(ans.begin(),ans.end());
		for(int i=0;i<SZ(ans);i++)
			printf("%c",ans[i]+'a');
		cout << endl;
	}
	return 0;
}
