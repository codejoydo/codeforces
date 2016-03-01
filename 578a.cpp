#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair< int, int >

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	if(a<b)
		cout << -1 << endl;
	else if(a==b)
		cout << a << endl;
	else if(a>b){
		int c=a-b;//y=x 
		int d=a+b;//y=-x
		int nc=c/b;
		int nd=d/b;
		int nnc=floor(nc);
		int nnd=floor(nd);
		if(nnc&1)nnc--;
		if(nnd&1)nnd--;
//		cout << nnc << endl;
//		cout << nnd << endl;
		double ac=c/(double)nnc;
		double ad=d/(double)nnd;
		double  ans = min(ac,ad); 
		printf("%.9lf\n",ans);	
	}
	return 0;
}
