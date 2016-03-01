#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,c,d,e,f,sum=0;
	cin >> a >> b >> c >> d >> e >> f;
	for(long long i=0;i<min(c,e);i++){
		sum+=d+i+d+i+1;
	}
//	cout << sum << endl;
	for(long long i=0;i<max(c,e)-min(c,e);i++){
		sum+=2*(min(c,e)+d);
	}
//	cout << sum << endl;
	for(long long i=0;i<min(b,f);i++){
		sum+=a+i+a+i+1;
	}
//	cout << sum << endl;
	cout << sum << endl;
	return 0;
}
