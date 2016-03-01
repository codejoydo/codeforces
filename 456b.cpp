#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[4]={1,1,1,1};
	int b[4]={6,2,4,8};
	int c[4]={1,3,9,7,};
	int d[4]={6,4,6,4};
	string s;
	cin >> s;
	s="000"+s;
	int i=(s[s.length()-2]*10+s[s.length()-1])%4;
	if(atoi(s.c_str())==0)
		cout << 4 << endl;
	else
		cout << (a[i]+b[i]+c[i]+d[i])%5 << endl;
	return 0;
}
