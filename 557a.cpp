#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a1,a2,b1,b2,c1,c2,p,q,r;
	cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	n-=a1+b1+c1;
	p=a1;
	q=b1;
	r=c1;
	if(n>a2-a1){
		n-=a2-a1;
		p+=a2-a1;
		if(n>b2-b1){
			n-=b2-b1;
			q+=b2-b1;
			if(n>c2-c1){
				n-=c2-c1;
				r+=c2-c1;
			}
			else if(n>0){
				r+=n;
				n=0;
			}
		}
		else if(n>0){
			q+=n;
			n=0;
		}
	}
	else if(n>0){
		p+=n;
		n=0;
	}
	cout << p << ' ' << q << ' ' << r << endl;
	return 0;
}

		

