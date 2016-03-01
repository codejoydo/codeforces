#include<bits/stdc++.h>

using namespace std;

int main(){
	double a,b,c,d,r1,r2;
	cin >> a >> b >> c;
	d=b*b-4*a*c;
	if(d){
		r1=(-1*b+sqrt(d))/(2*a);
		r2=(-1*b-sqrt(d))/(2*a);
		if(r1>r2)
			cout << r2 << ' ' << r1 << endl;
		else
			cout << r1 << ' ' << r2 << endl;
	}
	else{
		r1=(-1*b)/(2*a);
		cout << r1 << endl;
	}
	return 0;
}
