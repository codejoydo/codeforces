#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,temp;
	set<int> s;
	cin >> a;
	for(;;){
		temp=++a;
		for(int i=0;i<4;i++){
			s.insert(temp%10);
			temp/=10;
		}
		if(s.size()==4){
			cout << a << endl;
			return 0;
		}
		s.clear();
	}
}
		
		
