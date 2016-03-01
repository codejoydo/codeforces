#include<bits/stdc++.h>

using namespace std;

int main(){
	string n;
	cin >> n;
	for(int i=0;i<n.length();i++)
		for(int j=i+1;j<n.length();j++)
			for(int k=j+1;k<n.length();k++)
				if((100*(n[i]-'0')+10*(n[j]-'0')+(n[k]-'0'))%8==0){
					cout << "YES" << endl;
					cout << (100*(n[i]-'0')+10*(n[j]-'0')+(n[k]-'0')) << endl;
					return 0;
				}
	for(int j=0;j<n.length();j++)
		for(int k=j+1;k<n.length();k++)
			if((10*(n[j]-'0')+(n[k]-'0'))%8==0){
				cout << "YES" << endl;
				cout << (10*(n[j]-'0')+(n[k]-'0')) << endl;
				return 0;
			}
	for(int k=0;k<n.length();k++)
		if((n[k]-'0')%8==0){
			cout << "YES" << endl;
			cout << (n[k]-'0') << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}

