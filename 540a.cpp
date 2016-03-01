#include<bits/stdc++.h>

using namespace std;

string a,b;
int main(){
	int n,ans=0;
	cin >> n >> a >> b;
	for(int i=0;i<n;i++)
		ans+=min(min(abs(a[i]-b[i]),abs(a[i]+10-b[i])),abs(b[i]+10-a[i]));
	cout << ans << endl;
	return 0;
}

