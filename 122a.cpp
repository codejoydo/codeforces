#include<bits/stdc++.h>

using namespace std;

int check(int num){
	set<int> s;
	string n;
	stringstream c;
	c << num;
	n=c.str();
	for(int i=0;i<n.length();i++)
		s.insert(n[i]-'0');
	if(s.size()==2 && s.find(4)!=s.end() && s.find(7)!=s.end())
		return 1;
	if(s.size()==1 && s.find(4)!=s.end())
		return 1;
	if(s.size()==1 && s.find(7)!=s.end())
		return 1;
	return 0;
}

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		if(check(i) && n%i==0){
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;	
	return 0;
}
