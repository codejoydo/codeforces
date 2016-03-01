#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n==1||n==2)
		cout << "1\n1\n";
	else if(n==3)
		cout << "2\n1 3\n";
	else if(n==4)
		cout << "4\n2 4 1 3\n";
	else{
		cout << n << endl;
		vector<int> a(n);
		int cnt=1;
		for(int i=0;i<n;i+=2)
			a[i]=cnt++;
		for(int i=1;i<n;i+=2)
			a[i]=cnt++;
		for(int i=0;i<n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}

