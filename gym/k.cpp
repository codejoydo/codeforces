#include<bits/stdc++.h>

using namespace std;
#define push_back pb


int main(){
	int n;
	cin >> n;
	if(n&1){
		cout << "Yes" << endl;
		for(int i=1;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(j&1)	cout << 0 << ' ';
				else cout << 1 << ' ';
			}
			cout << endl;
		}
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}
