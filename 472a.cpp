#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n&1)
		cout << 9 << ' ' << n-9 << endl;
	else
		cout << 8 << ' ' << n-8 << endl;
	return 0;
}
