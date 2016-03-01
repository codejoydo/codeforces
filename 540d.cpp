#include<bits/stdc++.h>

using namespace std;

int a[105][105][105];
int main(){
	int r,s,p;
	cin >> r >> s >> p;
	double total=r*s+r*p+s*p;
	pr=1;ps=1;pp=1;
	if(r)
		pr*=((r*p)/total)+f(r-1,s,p);
	if(s)
		ps*=((r*s)/total)+f(r,s-1,p);
	if(p)
		pp*=((s*p)/total)+f(r,s,p-1);
	cout << pr << endl;
	cout << ps << endl;
	cout << pp << endl;
	return 0;
}

