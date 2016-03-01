#include<bits/stdc++.h>

using namespace std;

int bus(const vector<int>& v,const int& n){
	int n1=0,n2=0;
	for(int i=0;i<n;i++)
		if(v[i]==1)
			n1++;
		else if(v[i]==2)
			n2++;
	if(n1==2 && n2==n-2)
		return 1;
	return 0;
}

int star(const vector<int>& v,const int& n){
	int n1=0,ncenter=0;
	for(int i=0;i<n;i++)
		if(v[i]==1)
			n1++;
		else if(v[i]==n-1)
			ncenter++;
	if(n1==n-1 && ncenter==1)
		return 1;
	return 0;
}

int ring(const vector<int>& v,const int& n){
	int n2=0;
	for(int i=0;i<n;i++)
		if(v[i]==2)
			n2++;
	if(n2==n)
		return 1;
	return 0;
}

int main(){
	int n,m,p,q;
	vector<int> v;
	cin >> n >> m;
	v.resize(n);
	for(int i=0;i<m;i++){
		cin >> p >> q;
		v[p-1]++;
		v[q-1]++;
	}
	if(bus(v,n))
		cout << "bus topology" << endl;
	else if(ring(v,n))
		cout << "ring topology" << endl;
	else if(star(v,n))
		cout << "star topology" << endl;
	else
		cout << "unknown topology" << endl;
	return 0;
}	
