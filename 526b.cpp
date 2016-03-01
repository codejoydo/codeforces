#include<bits/stdc++.h>

using namespace std;

int pw(const int& n){
	int ans=1;
	for(int i=0;i<n;i++)
		ans*=2;
	return ans;
}

int main(){
	vector<int> a;
	int n,ans=0;
	cin >> n;
	a.resize(pw(n+1));
	for(int i=2;i<pw(n+1);i++)
		cin >> a[i];
	for(int i=pw(n+1)-1;i>=2;i-=2){
		if(a[i]>a[i-1]){
			ans+=a[i]-a[i-1];
			a[i/2]+=a[i];
		}
		else{
			ans+=a[i-1]-a[i];
			a[i/2]+=a[i-1];
		}
	}
	cout << ans << endl;
	return 0;
}


