#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ans=0;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++){
		if(s[i]-'0')
			ans++;
		else 
			ans--;
	}
	if(ans<0)
		ans*=-1;
	cout << ans << endl;
	return 0;
}
