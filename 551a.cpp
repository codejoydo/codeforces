#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a,b,ans;
	int n,count=1,label=1;
	cin >> n;
	a.resize(n);
	b.resize(n);
	ans.resize(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	b=a;
	sort(a.begin(),a.end());
//	for(int i=0;i<n;i++){
//		cout << a[i] << ' ';
//	}
//	cout << endl;
	for(int i=n-1;i>=0;i--){
		if(i)
			while(a[i]==a[i-1])
				i--;
		for(int j=0;j<n;j++){
			if(b[j]==a[i]){
//				cout << j << endl;
				ans[j]=label;
				count++;
			}
		}
		label=count;
	}
	for(int i=0;i<n;i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
