#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m,p,q,ans=0;
	vector<int> a;
	cin >> n >> m;
	while(n--){ 
		cin >> p;
		a.push_back(p);
	}
	while(m--){
		cin >> p >> q;
		ans+=(a[p-1]>a[q-1])?(a[q-1]):(a[p-1]);
	}
	cout << ans << endl;
	return 0;
}
