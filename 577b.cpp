#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int a[1005];

int gcd(int a,int b){
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}

int check(int m){
	for(int i=1;i<=m/2;i++){
		if(a[i]>1){
			a[2*i]+=a[i]/2;
			a[i]=a[i]-2*(a[i]/2);
		}
	}
	if(a[0]||a[m])
		return 1;
	for(int i=m-1;i>=1;i--){
		int x = (m/gcd(m,i)) ;
		if(a[i]>=x)
			return 1;
		else if(a[i]){
			if(a[m-i])
				return 1;
			else
				check(m-i);
		}
	}
	return 0;
}

int main(){
	int n,m,tp;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		scanf("%d",&tp);
		a[tp%m]++;
	}
	int ans=check(m);
	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}
