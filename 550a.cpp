#include<bits/stdc++.h>

using namespace std;

int main(){
	string a;
	vector<int> p,q;
	cin >> a;
	for(int i=0;i<a.length()-1;i++){
		if(a[i]=='A' && a[i+1]=='B'){
			p.push_back(i);
		}
		else if(a[i]=='B' && a[i+1]=='A'){
			q.push_back(i);
		}
	}
	for(int i=0;i<p.size();i++)
		for(int j=0;j<q.size();j++)
			if(p[i]!=q[j]+1 && q[j]!=p[i]+1){
				cout << "YES\n";
				return 0;
			}
	cout << "NO\n";
	return 0;
}

