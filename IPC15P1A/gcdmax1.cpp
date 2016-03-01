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

int foo(int a,int b){
	int r;
	while(a!=0){
		r=b%a;
		b=a;
		a=r;
	}
	return b;
}

int a[500005];
int gcd[725];
const int sqn = 720;
int main(){
	int n,kk;
	si(n);si(kk);
	for(int i=0;i<n;i++) si(a[i]);
	for(int i=0;i<n;i+=sqn){
		gcd[i/sqn]=a[i];
		for(int j=i;j<(((i/sqn)+1)*sqn) && j<n;j++){
			trace(a[j]);
			gcd[i/sqn]=foo(gcd[i/sqn],a[j]);
		}
		trace(gcd[i/sqn]);
	}
	int lmax=0,l1=0,l2=0,cd=0,j=0,cblk=0;
	bool fl;
	for(int i=0;i<n;i++){
		fl=false;
		cd=a[i],l1=0,l2=0;
		for(j=i;j<(((i/sqn)+1)*sqn) && j<n;j++){
			cd=foo(a[j],cd);
			trace(i,j,cd);
			if(cd<kk){
				fl=true;
				break;
			}
			l1++;
			lmax=max(lmax,l1);
		}
		trace(l1,j);
		if(fl) continue;
		int tcd;
		for(int k=j/sqn;k<n/sqn;k++){
			trace(k,gcd[k]);
			tcd=cd;
			cd=foo(gcd[k],cd);
			if(cd<kk){
				break;
			}
			j+=sqn;
			l1+=sqn;
		}
		cd=tcd;
		//cout << "after bloks" << endl;
		trace(l1,j);
		lmax=max(lmax,l1);
		for(int k=j;k<j+sqn && k<n;k++){
			cd=foo(a[k],cd);
			trace(i,k,a[k],cd);
			if(cd<kk){
				fl=true;
				break;
			}
			l1++;
			lmax=max(lmax,l1);
		}
	}
	cout << lmax << endl;
	return 0;
}
