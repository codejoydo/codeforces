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

int p[2000010];
int a[1005];
int main(){
	p[1] = 1;
	for(int i=2;i*i<2000006;i++){
		if(!p[i]){
			for(int j=2*i;j<2000006;j+=i)
				p[j] = 1;
		}
	}
	int n;
	si(n);
	int c1 = 0;
	for(int i=0;i<n;i++){
	   	si(a[i]);
		if(a[i] == 1) c1++;
	}

	VI v1,v2,v3,ans;

	for(int i=0;i<c1;i++) v1.PB(1);
	if(c1)
	for(int i=0;i<n;i++){
	   	if(a[i]!=1 and p[a[i]+1]==0){
	   		v1.PB(a[i]);
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(a[i]==1) continue;
		for(int j=0;j<n;j++){
			if(a[j]==1) continue;
			if(j==i) continue;
			if(p[a[i]+a[j]]==0){
				v2.PB(a[i]);
				v2.PB(a[j]);
			}
			if(SZ(v2)) break;
		}
		if(SZ(v2)) break;
	}
	
	v3.PB(a[0]);

	if(SZ(ans)<SZ(v1)) ans = v1;	
	if(SZ(ans)<SZ(v2)) ans = v2;	
	if(SZ(ans)<SZ(v3)) ans = v3;	
	dout(SZ(ans));
	for(int i=0;i<SZ(ans);i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
	return 0;
}
