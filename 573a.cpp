#include<bits/stdc++.h>

using namespace std;

int a[100005];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		while(a[i]%2==0)
			a[i]/=2;
		while(a[i]%3==0)
			a[i]/=3;
//		cout << a[i] << endl;
	}
	for(int i=0;i<n-1;i++)
		if(a[i]!=a[i+1]){
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}
