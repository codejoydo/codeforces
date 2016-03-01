#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a;
	int n,m,min=1234;
	cin >> n >> m;
	a.resize(m);
	for(int i=0;i<m;i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	for(int i=n-1;i<m;i++)
		if(a[i]-a[i-n+1]<min)
			min=a[i]-a[i-n+1];
	cout << min << endl;
	return 0;
}
