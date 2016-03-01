#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ans;
	cin >> n;
	if(n<0){
		n*=-1;
		ans=(n/10<(n/100)*10+n%10)?(n/10):((n/100)*10+n%10);
		cout << -1*ans << endl;
	}
	else
		cout << n << endl;
	return 0;
}
