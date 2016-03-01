#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ans=0;
	cin >> n;
	if(n==1){
		cout << "YES\n" << "2 1\n" << "1 2\n";
		return 0;
	}
	if(n&1){
		cout << "YES" << endl;
		cout << 2*n+4 << ' ' << (n+2)*n << endl;
		for(int i=2;i<=n;i++){
			cout << 1 << ' ' << i << endl;
			cout << 1+n+2 << ' ' << i+n+2 << endl;
			for(int j=i+1;j<=n;j++)
				if(!(i%2==0 && j==i+1)){
//					cout << i << ':' << j << endl;
//				}
//				else{
					cout << i << ' ' << j << endl;
					cout << i+n+2 << ' ' << j+n+2 << endl;
				}
			cout << i << ' ' << n+1 << endl;
			cout << i << ' ' << n+2 << endl;
			cout << i+n+2 << ' ' << 2*n+3 << endl;
			cout << i+n+2 << ' ' << 2*n+4 << endl;
		}
		cout << n+1 << ' ' << n+2 << endl;
		cout << 2*n+3 << ' ' << 2*n+4 << endl;
		cout << 1 << ' ' << n+3 << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}
