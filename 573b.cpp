#include<bits/stdc++.h>

using namespace std;

int a[100005],b[100005],c[100005];
int main(){
	int n,mn1,mn2,mx=0;
	cin >> n;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	mn1=mn2=1;
	for(int i=0;i<n;i++){
		int j = n-1-i;
		if(mn1>a[i])
			mn1=a[i];
		if(mn2>a[j])
			mn2=a[j];
		b[i]=mn1;
		c[j]=mn2;
		mn1++;
		mn2++;
	}
	for(int i=0;i<n;i++)
		if(mx<min(b[i],c[i]))
			mx=min(b[i],c[i]);
	cout << mx << endl;
	return 0;
}
