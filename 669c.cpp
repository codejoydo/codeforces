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
int A[105][105];
int main(){
	vector<pair<II,II>> Q;
	int n,m,q;
	si(n);si(m);si(q);
	for(int i=0;i<q;i++){
		int t,l,r,v;
		si(t);
		if(t==1 or t==2){
			si(v);
			v--;
			l = 0;
			r = 0;
		}
		else{
			si(l);si(r);si(v);
			l--;r--;
		}
		Q.PB(MP(MP(t,v),MP(l,r)));
	}
	for(int i=q-1;i>=0;i--){
		int t = Q[i].F.F;
		int v = Q[i].F.S;
		int l = Q[i].S.F;
		int r = Q[i].S.S;
		if(t==1){
			int tp = A[v][m-1];
			for(int i=m-1;i>=1;i--)
				A[v][i] = A[v][i-1];
			A[v][0] = tp;
		}
		else if(t==2){
			int tp = A[n-1][v];
			for(int i=n-1;i>=1;i--)
				A[i][v] = A[i-1][v];
			A[0][v] = tp;
		}
		else{
			A[l][r] = v;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<A[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
