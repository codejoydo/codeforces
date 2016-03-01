#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j;
	vector<int> a;
	cin >> n;
	a.resize(n);
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j&1)
				a[j]=(a[j]+n-1)%n;
			else
				a[j]=(a[j]+1)%n;
		}
//		for(j=0;j<n;j++){
//			cout << a[j] << ' ';
//		}
//		cout << endl;
		for(j=0;j<n;j++)
			if(a[j]!=j)
				break;
		if(j==n){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
