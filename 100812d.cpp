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

LL a[200005];
LL p[200005];
map< LL,VI > m;
int main(){
	int n;
	bool win=false;
	int index;
	si(n);
	p[0]=0;
	m[p[0]].PB(0);
	for(int i=1;i<=n;i++){
	 	sll(a[i]);
		if(a[i]==0 && win==false){
			win=true;
			index=i;
		}
		p[i]=p[i-1]+a[i];
		m[p[i]].PB(i);
	}
	
	if(win){
		cout << index << ' ' << 1 << endl;
		return 0;
	}
	int min=2e9,start;
	for(auto it=m.begin();it!=m.end();++it){
		for(int i=0;i<SZ(it->S)-1;i++){
			if(it->S[i+1]-it->S[i]<min){
				min=it->S[i+1]-it->S[i];
				start=it->S[i]+1;
			}
		}
	}
	if(min==2e9)
		cout << -1 << endl;
	else
		cout << start << ' ' << min << endl;
	return 0;
}
