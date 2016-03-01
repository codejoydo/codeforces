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

struct node{
	int l,r,c,i;
}q[100005];
VI g[200005];
VI v;
int c[200005], timee=0, in[200005], out[200005], vs[200005], cnt[100005], f[100005], minn, ans=0;
const int block =	447;

bool foo(struct node a,struct node b){
	if(a.l/block!=b.l/block)
		return a.l/block < b.l/block;
	return a.r < b.r;
}

void dfs(int u){
	trace(u);
	vs[u]=1;
	in[u]=timee++;
	v.PB(c[u]);
	for(int i=0;i<SZ(g[u]);i++){
		int w = g[u][i];
		if(!vs[w])
			dfs(w);
	}
	out[u]=timee;
}

void add(int i){
	cnt[v[i]]++;
	if(v[i]==minn)
		ans++;
}

void remove(int i){
	cnt[v[i]]--;
	if(v[i]==minn-1)
		ans--;
}

int main(){
	int n,m,a,b;
	si(n);si(m);
	for(int i=1;i<=n;i++) si(c[i]);
	for(int i=1;i<n;i++){
		si(a);si(b);
		g[a].PB(b);
		g[b].PB(a);
	}
	dfs(1);
	for(int i=0;i<SZ(v);i++)
		cout << v[i] << ' ';
	cout << endl;
	for(int i=0;i<m;i++){
		si(a);si(b);
		q[i].l = in[a];
		q[i].r = out[a];
		q[i].c = b;
		q[i].i = i;
	}
	sort(q,q+m,foo);	
	int L=0, R=0;
	for(int i=0;i<m;i++){
		int l = q[i].l;
		int r = q[i].r;
		trace(l,r);
		int j = q[i].i;
		minn = q[i].c;
		while(L<l){
			remove(L);
			L++;
		}	
		while(L>l){
			remove(L-1);
			L--;
		}
		while(R<=r){
			add(R);
			R++;
		}
		while(R>r+1){
			remove(R-1);
			R--;
		}
		f[j] = ans;
	}
	for(int i=0;i<m;i++) dout(f[i]);
	return 0;
}
