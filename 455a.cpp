#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,foo,mx=0;
	vector<long long> c(100007);
	vector<long long> dp(100007);
	cin >> n;
	for(long long i=0;i<n;i++){
		cin >> foo;
		if(foo>mx)
			mx=foo;
		c[foo]++;
	}
	dp[0]=0;
	dp[1]=c[1];
	for(long long i=2;i<=mx;i++)
		dp[i]=max(dp[i-1],dp[i-2]+c[i]*i);
	cout << dp[mx] << endl;
	return 0;
}
