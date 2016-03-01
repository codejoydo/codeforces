#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,num;
	set<int> s;
	cin >> n;
	cin >> a;
	while(a--){
		cin >> num;
		s.insert(num);
	}
	cin >> b;
	while(b--){
		cin >> num;
		s.insert(num);
	}
	if(s.size()==n)
		cout << "I become the guy." << endl;
	else
		cout << "Oh, my keyboard!" << endl;
	return 0;
}
		
