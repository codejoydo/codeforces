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
#define BLOCK 320
const int N = 1<<20 + 5;
int n,m,k;
int a[100005];
LL ans[100005];
int cnt[N];
LL answer = 0;

struct node {
	  int L, R, id;
}q[100005];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>a[i+1];
	for(int i=1;i<=n;i++) a[i] = a[i-1]^a[i];
	for(int i=0; i<m; i++){
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; 
		q[i].id = i;
	}
	sort(q, q + m, cmp);
	int l = 0, r = -1;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		//adds
		while(r < R) {
			answer += cnt[a[++r]^k];
			cnt[a[r]]++;
		}
		while(l > L) {
			answer += cnt[a[--l]^k];
			cnt[a[l]]++;
		}
		//removes
		while(l < L) {
			cnt[a[l]]--;
			answer -= cnt[a[l++]^k];
		}
		while(r > R) {
			cnt[a[r]]--;
			answer -= cnt[a[r--]^k];
		}
		ans[q[i].id] = answer;
	}

	for(int i=0; i<m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
