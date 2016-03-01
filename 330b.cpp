#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,t,p,q;
	vector<int> a;
	cin >> n >> t;
	a.resize(n);
	while(t--){
		cin >> p >> q;
		a[p-1]=1;
		a[q-1]=1;
	}
	for(int i=0;i<n;i++)
		if(!a[i]){
			p=i+1;
			break;
		}
	cout << n-1 << endl;
	for(int i=0;i<n;i++){
		if(i==p-1)
			continue;
		cout << p << ' ' << i+1 << endl;
	}
	return 0;
}

