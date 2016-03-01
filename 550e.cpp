#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,j;
	vector<int> a;
	cin >> n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(a[n-1]==1){
		cout << "NO" <<  endl;
		return 0;
	}
	else{
		if(n==1 && a[0]==0)
			cout << "YES\n" << "0" << endl;
		else if(a[n-2]==1){
			cout << "YES" << endl;
			for(int i=0;i<n-1;i++)
				cout << a[i] << "->";
			cout << a[n-1] << endl;
		}
		else{
			j=n-3;
			while(a[j]==1 && j>=0)
				j--;
			if(j<0){
				cout << "NO" << endl;
				return 0;
			}
			else{
				cout << "YES" << endl;
				for(int i=0;i<j;i++)
					cout << a[i] << "->";
				cout << '(' << a[j] << "->" << '(';
				for(int i=j+1;i<n-2;i++)
					cout << a[i] << "->";
				cout << a[n-2] << "))->" << a[n-1] << endl;
			}
		}
	}
	return 0;
}

