#include<bits/stdc++.h>

using namespace std;

long long a[200005],b[200005],c[200005];

int main(){
	long long n,k,x,m=1,mx=0,ans;
	cin>>n>>k>>x;
	while(k--) m*=x;
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	b[0]=a[0];
	c[n-1]=a[n-1];
	for(int i=1;i<n;i++) b[i]=b[i-1]|a[i];
	for(int i=n-2;i>=0;i--) c[i]=c[i+1]|a[i];
	for(int i=0;i<n;i++){
		a[i]*=m;
		if(i==0)
			ans=a[i]|c[i+1];
		else if(i==n-1)
			ans=a[i]|b[i-1];
		else
			ans=a[i]|b[i-1]|c[i+1];
		if(mx<ans)
			mx=ans;
	}
	cout << mx << endl;		
	return 0;
}
