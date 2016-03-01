#include<bits/stdc++.h>

using namespace std;

long long a,b[100005];
vector<long long> v;
int main(){
	long long n,m,max,p;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		max=-1;
		for(int j=0;j<n;j++){
			cin >> a;
			if(max<a){
				p=j;
				max=a;
			}
		}
		b[p]++;
	}
	max=-1;
	for(int i=0;i<n;i++){
//		cout << i+1 << ' ' << b[i] << endl;
		if(max<b[i]){
			p=i;
			max=b[i];
		}
	}
	cout << p+1 << endl;
	return 0;
}
