#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[1234567];
	for(int i=0;i<n;i++){
		cin >>a[i];
		if(a[i]==1){
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << "1" << endl;
	return 0;
}
