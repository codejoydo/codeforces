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

int a[1003][1003];
int main(){
	int n;
	LL cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x][y] = 1;
	}
	LL p,q,fl;
	for(int i=0;i<=1000;i++){
		p = 0;
		q = i;
		fl = 0;
		while(p<=1000 and q<=1000){
			if(a[p][q]) fl++;
			p++;
			q++;
		}
		cnt += (fl*(fl-1))/2;
		if(i){
			p=i;
			q=0;
			fl=0;
			while(p<=1000 and q<=1000){
				if(a[p][q]) fl++;
				p++;
				q++;
			}
			cnt += (fl*(fl-1))/2;
		}
		p=0;
		q=i;
		fl=0;
		while(p<=1000 and q>=0){
			if(a[p][q]) fl++;
			p++;
			q--;
		}
		cnt += (fl*(fl-1))/2;
		if(i){
			p=i;
			q=1000;
			fl=0;
			while(p<=1000 and q>=0){
				if(a[p][q]) fl++;
				p++;
				q--;
			}
			cnt += (fl*(fl-1))/2;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
