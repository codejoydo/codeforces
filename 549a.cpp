#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,ans=0;
	set<int> s;
	vector< vector<int> > ar(100,vector<int>(100));
	cin >> a >> b;
	getchar();
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)
			ar[j][i]=getchar();
		getchar();
	}
//	for(int i=0;i<a;i++){
//		for(int j=0;j<b;j++)
//			cout << ar[j][i] << ' ';
//		cout << endl;
//	}
	for(int i=0;i<a-1;i++)
		for(int j=0;j<b-1;j++){
//			cout << i << ' ' << j << endl;
			s.insert(ar[j][i]);
			s.insert(ar[j+1][i]);
			s.insert(ar[j][i+1]);
			s.insert(ar[j+1][i+1]);
			if(s.find(102)!=s.end() && s.find(97)!=s.end() && s.find(99)!=s.end() && s.find(101)!=s.end()){
				ans++;
			}
			s.clear();
		}
	cout << ans << endl;
	return 0;
}	
