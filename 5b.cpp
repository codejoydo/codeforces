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
vector<string> v;
string s;
int main(){
	int mx = 0;
	while(getline(cin,s)){
		v.PB(s);
		mx = max(SZ(s),mx);
	}
	int fl = 1;
	for(int i=0;i<mx+2;i++){
		cout<<'*';
	}
	cout<<endl;
	for(int i=0;i<SZ(v);i++){
		cout<<'*';
		int d = mx - SZ(v[i]),l,r;
		r = d/2;
		l = (d+1)/2;
		if(d&1){
			if(fl){
		   		swap(l,r);
				fl = 0;
			}
			else{
				fl = 1;
			}
		}
		for(int j=0;j<l;j++){
			cout<<' ';
		}
		cout<<v[i];
		for(int j=0;j<r;j++){
			cout<<' ';
		}
		cout<<'*'<<endl;
	}
	for(int i=0;i<mx+2;i++){
		cout<<'*';
	}
	cout<<endl;
	return 0;
}
