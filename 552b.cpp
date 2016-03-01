#include<bits/stdc++.h>

using namespace std;

int pw(const int& num){
	int ans=1;
	for(int i=0;i<num;i++)
		ans*=10;
	return ans;
}

int main(){
	long long ans=0;
	int n,tp;
	cin >> n;
	for(int i=0;i<=9;i++){
		tp=n-pw(i)+1;
		if(tp<0)
			tp=0;
		ans+=tp;
	}
	cout << ans << endl;
}
