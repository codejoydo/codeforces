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

int a[200005];
int st[200005];
int l,n,m,x;

void initialise(int node,int l,int r,int lev){
	if(l == r){
		st[node] = a[l];
		return;
	}
	int mid = l + (r-l)/2;
	initialise(node*2,l,mid,lev-1);
	initialise(node*2+1,mid+1,r,lev-1);
	if(lev&1) st[node] = st[node*2]|st[node*2+1];
	else			st[node] = st[node*2]^st[node*2+1];
}

void update(int node,int l,int r,int index,int key,int lev){
	if(l <= index  and index <= r){
		if(l == r){
			st[node] = key;
			return;
		}
		int mid = l + (r-l)/2;
		update(node*2,l,mid,index,key,lev-1);
		update(node*2+1,mid+1,r,index,key,lev-1);
		if(lev&1) st[node] = st[node*2]|st[node*2+1];
		else			st[node] = st[node*2]^st[node*2+1];
	}
	return;
}

int main(){
	cin>>l>>m;
	x = l;
	n = 1<<l;
	for(int i=0;i<n;i++){
		cin >> a[i];
		st[i] = -1;
	}
	initialise(1,0,n-1,x);
	while(m--){
		int index,key;
		cin>>index>>key;
		index--;
		update(1,0,n-1,index,key,x);
		cout << st[1] << endl;
	}	
	return 0;
}
