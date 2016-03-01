#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,c,l,diff,sub,mn;
	cin >> a >> b >> c >> l;
	long long ans = (l+3)*(l+1)*(l+2);
	ans/=6;
//	cout << ans << endl;
	for(long long i=max(a+b,c);i<=c+l;i++){
		diff = i-(a+b);
		if(diff<0)
			continue;
		mn=min(diff,l-i+c);
//		cout << a+b << ' ' << c+i << ' ' << mn << endl;
		sub = (mn+2)*(mn+1);
		sub/=2;
		ans-=sub;
	}
	for(long long i=max(c+b,a);i<=a+l;i++){
		diff = i-(c+b);
		if(diff<0)
			continue;
		mn=min(diff,l-i+a);
//		cout << a+b << ' ' << c+i << ' ' << mn << endl;
		sub = (mn+2)*(mn+1);
		sub/=2;
		ans-=sub;
	}
	for(long long i=max(a+c,b);i<=b+l;i++){
		diff = i-(a+c);
		if(diff<0)
			continue;
		mn=min(diff,l-i+b);
//		cout << a+b << ' ' << c+i << ' ' << mn << endl;
		sub = (mn+2)*(mn+1);
		sub/=2;
		ans-=sub;
	}
	cout << ans << endl;
	return 0;
}
	


