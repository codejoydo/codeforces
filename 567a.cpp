#include<bits/stdc++.h>

using namespace std;

int a[100005];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int mn=a[0];
	int mx=a[n-1];
	printf("%d %d\n",a[1]-a[0],mx-mn);
	for(int i=1;i<n-1;i++)
		printf("%d %d\n",min(a[i]-a[i-1],a[i+1]-a[i]),max(mx-a[i],a[i]-mn));
	printf("%d %d\n",a[n-1]-a[n-2],mx-mn);
	return 0;
}


