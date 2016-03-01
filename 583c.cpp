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


int a[300005];
map<int,int> m;
set<int> s;
VI v;

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	int n;
	si(n);
	for(int i=0;i<n*n;i++){
		si(a[i]);
		m[a[i]]++;
		s.insert(a[i]);
	}
	while(SZ(v)<n){
		auto it = s.end();it--;
		int x=*it;
//		trace(x);
		v.PB(x);
		m[x]--;
		if(m[x]==0){
			s.erase(x);
		}
		for(int i=0;i<SZ(v)-1;i++){
			int g=gcd(v[i],x);
			m[g]-=2;
			if(m[g]==0)
				s.erase(g);
		}
	}
	for(int i=0;i<n;i++){
		cout << v[i] << ' ';
	}
	cout << endl;



	return 0;
}
