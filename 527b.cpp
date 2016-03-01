#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ham=0,sa=-1,sb=-1;
	string a,b,c="",d="";
	vector<int> id;
	vector< vector<int> > foo(26,vector<int>(0)),fun(26,vector<int>(0));
	cin >> n >> a >> b;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]){
			ham++;
			foo[a[i]-'a'].push_back(i);
			fun[b[i]-'a'].push_back(i);
			c+=a[i];
			d+=b[i];
			id.push_back(i);
		}
	for(int i=0;i<26;i++)
		if(!foo[i].empty() && !fun[i].empty()){
			sa=foo[i][0]+1;
			sb=fun[i][0]+1;
			break;
		}
	for(int i=0;i<c.length();i++)
		for(int j=0;j<c.length();j++)
			if(c[i]==d[j] && d[i]==c[j]){
				cout << ham-2 << endl;
				cout << id[i]+1 << ' ' << id[j]+1 << endl;
				return 0;
			}
	if(sa!=-1 && sb!=-1){	
		cout << ham-1 << endl;
		cout << sa << ' ' << sb << endl;
		return 0;
	}	
	cout << ham << "\n" << "-1 -1" << endl;
	return 0;
}

