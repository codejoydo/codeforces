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
const int N = 100005;
int len[3];
char a[3][N];
int q1=0,q2=1,q3=2;
LL H[3][2][N],b1=256,b2=512,p1=1e9+9,p2=1e9+411,bb1,bb2,inv1,inv2,P1[N],P2[N];
LL powmod(LL a,int n,LL mod){
	if(!n) return 1LL;
	if(n&1) return a*powmod(a,n-1,mod)%mod;	
	LL tp = powmod(a,n/2,mod);
	return tp*tp%mod;
}
typedef pair<LL,LL> PLL;
PLL null = {-1,-1};
PLL gethash(int id,int l,int r){
	if(r>=len[id]) return null;
	if(!l) return {H[id][0][r],H[id][1][r]};
	return {((H[id][0][r]-H[id][0][l-1]+p1)*P1[l])%p1,((H[id][1][r]-H[id][1][l-1]+p2)*P2[l])%p2};
}
int check(int id1,int id2){
	if(len[id2]<len[id1]) return 0;
	for(int i=0;i<=len[id2]-len[id1];i++){
		if(gethash(id1,0,len[id1]-1) == gethash(id2,i,i+len[id1]-1)){
			//trace(i);
			return 1;
		}
	}
	return 0;
}
int match(int id1,int id2){
	int ret = 0;
	int n = min(len[id1],len[id2]);
	for(int i=0;i<n;i++){
		if(gethash(id1,len[id1]-i-1,len[id1]-1) == gethash(id2,0,i)){
			ret = i+1;
		}
	}
	return ret;
}
int solve(int id1,int id2,int id3){
	int m1 = match(id1,id2);
	int m2 = match(id2,id3);
	if(id1==id2 and id2==id3){
		return len[id1];
	}
	else if(id1==id2){
		return len[id2]+len[id3] - m2;
	}
	else if(id2==id3){
		return len[id1]+len[id2] - m1;
	}
	else if(id1==id3){
		return len[id1]+len[id2] - m1;
	}
	else{
		int ret = len[id1]+len[id2]+len[id3]-m1-m2;
		return ret;
	}
}
int main(){
	for(int i=0;i<3;i++){
		scanf("%s",a[i]);
		len[i] = strlen(a[i]);
	}
	inv1 = powmod(b1,p1-2,p1);
	inv2 = powmod(b2,p2-2,p2);
	P1[0] = P2[0] = 1;
	for(int i=1;i<N;i++){
		P1[i] = (P1[i-1]*inv1)%p1;
		P2[i] = (P2[i-1]*inv2)%p2;
	}
	for(int x=0;x<3;x++){
		bb1 = bb2 = 1;
		for(int i=0;i<len[x];i++){
			if(!i)
				H[x][0][i] = a[x][i],
				H[x][1][i] = a[x][i];
			else
				H[x][0][i] = (H[x][0][i-1] + a[x][i]*bb1) % p1,
				H[x][1][i] = (H[x][1][i-1] + a[x][i]*bb2) % p2;
			bb1 = (bb1 * b1) % p1;
			bb2 = (bb2 * b2) % p2;
		}
	}
	int ans = INT_MAX;
	if(check(0,1)) q1 = q2;
	if(check(1,0)) q2 = q1;
	if(check(1,2)) q2 = q3;
	if(check(2,1)) q3 = q2;
	if(check(0,2)) q1 = q3;
	if(check(2,0)) q3 = q1;
	ans = min(ans,solve(q1,q2,q3));	
	ans = min(ans,solve(q1,q3,q2));	
	ans = min(ans,solve(q2,q1,q3));	
	ans = min(ans,solve(q2,q3,q1));	
	ans = min(ans,solve(q3,q1,q2));	
	ans = min(ans,solve(q3,q2,q1));	
	dout(ans);
	return 0;
}
