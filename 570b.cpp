#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	if(n&1){
		int mid=n/2+1;
		if(m==mid)
			cout << m-1 << endl;
		else if(m<mid)
			cout << m+1 << endl;
		else
			cout << m-1 << endl;
	}
	else{
		int mid1=n/2,mid2=n/2+1;
		if(m==mid1)
			cout << mid2 << endl;
		else if(m==mid2)
			cout << mid1 << endl;
		else if(m<mid1)
			cout << m+1 << endl;
		else if(m>mid2)
			cout << m-1 << endl;
	}
	return 0;
}
