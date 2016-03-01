#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a=0,b=0,x;
	for(int i=0;i<3;i++){
		cin >> x;
		a+=x;
	}
	for(int i=0;i<3;i++){
		cin >> x;
		b+=x;
	}
	cin >> n;
	x=0;
	while(a>0){
		a-=5;
		x++;
	}
	while(b>0){
		b-=10;
		x++;
	}
	if(x<=n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
