#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
	int n,q,l,r;
	long long a,b,f[100005],ar[100005];
	vector<long long> p(100005);
	cin >> n >> q >> f[1] >> f[2] >> a >> b;
	for(int i=3;i<=n+2;i++)
		f[i]=((a*f[i-2])%MOD+(b*f[i-1])%MOD)%MOD;
	for(int i=1;i<=n;i++)
		scanf("%lld",&ar[i]);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		if(l<r){
			p[l]=(p[l]+f[1])%MOD;
			p[l+1]=(p[l+1]+f[2])%MOD;
			p[l+1]=(p[l+1]-(b*f[1])%MOD+MOD)%MOD;
			p[r+1]=(p[r+1]-f[r-l+2]+MOD)%MOD;
			p[r+2]=(p[r+2]-(a*f[r-l+1])%MOD+MOD)%MOD;
		}
		else{
			p[l]=(p[l]+f[1])%MOD;
			p[r+1]=(p[r+1]-(b*f[1])%MOD+MOD)%MOD;
			p[r+2]=(p[r+2]-(a*f[1])%MOD+MOD)%MOD;
		}
	}
	for(int i=1;i<=n;i++){
		if(i>1)
			p[i]=(p[i]+(a*p[i-2])%MOD+(b*p[i-1])%MOD)%MOD;
		else if(i==1)
			p[i]=(p[i]+(b*p[i-1])%MOD)%MOD;
		ar[i]=(ar[i]+p[i])%MOD;
		printf("%lld ",ar[i]);
	}
	cout << endl;
	return 0;
}

