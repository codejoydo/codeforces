#include<bits/stdc++.h>

using namespace std;

int main(){
	int i;
	string a;
	string b="";
	cin >> a;
	a="WUB"+a+"WUB";
	for(i=0;i<a.length()-2;i++){
		if(a[i]=='W' && a[i+1]=='U' && a[i+2]=='B'){
			b+=' ';
			i+=2;
		}
		else
			b+=a[i];
	}
	if(i!=a.length()){
		b+=a[a.length()-2]+a[a.length()-1];
	}
	for(i=0;i<b.length();i++){
		if('A'<=b[i] && b[i]<='Z'){
			cout << b[i];
			if(b[i+1]==' ')
				cout << ' ';
		}
	}
	cout << endl;
	return 0;
}
