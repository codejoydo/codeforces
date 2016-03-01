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
	int l,r,i;
}q[200005];
long long cnt[1000006];
long long a[200005];
long long f[200005];
const int block=447;
long long ans=0;

bool foo(struct node a,struct node b){
	if(a.l/block != b.l/block)
		return a.l/block < b.l/block;
	return a.r < b.r;
}

void add(int i){
	int x=a[i]*cnt[a[i]]*cnt[a[i]];
	cnt[a[i]]++;
	int s=a[i]*cnt[a[i]]*cnt[a[i]];
	ans+=s-x;
}

void remove(int i){
	int x=a[i]*cnt[a[i]]*cnt[a[i]];
	cnt[a[i]]--;
	int s=a[i]*cnt[a[i]]*cnt[a[i]];
	ans+=s-x;
}

int main(){
	int n,m,x,y;
	si(n);si(m);
	for(int i=0;i<n;i++) sll(a[i]);
	for(int i=0;i<m;i++){
		si(x);si(y);x--;y--;
		q[i].l=x;q[i].r=y;q[i].i=i;
	}
	sort(q,q+m,foo);
	int L=0,R=0;
	for(int i=0;i<m;i++){
		int l=q[i].l,r=q[i].r,j=q[i].i;
		while(L<l){
			remove(L);
			L++;
		}
		while(L>l){
			add(L-1);
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
		f[j]=ans;
	}
	for(int i=0;i<m;i++) lldout(f[i]);
	return 0;
}
