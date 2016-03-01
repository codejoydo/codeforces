#include<bits/stdc++.h>

using namespace std;

int a[1005],b[1000];
int main(){
	int n,s;
	cin >> n >> s;
	int sum=s,i;
	for(i=n-1;i>=0;i--){
		if(sum-9>0){
			a[i]=9;
			sum-=9;
		}
		else{
			a[i]=sum;
			sum=0;
			break;
		}
	}
	if(i<=0&&sum>0){
		cout << -1 << ' ' << -1 << endl;
		return 0;
	}
	else{
		for(i=0;i<n;i++)
			b[i]=a[n-1-i];
		if(a[0]==0 && n>1){
			int j;
			for(j=1;j<n;j++)
				if(a[j]){
					a[j]--;
					a[0]++;
					break;
				}
			if(j==n){
				cout << -1 << ' ' << -1 << endl;
				return 0;
			}
		}
		for(int i=0;i<n;i++)
			cout << a[i];
		cout << ' ';
		for(int i=0;i<n;i++)
			cout << b[i];
		cout << endl;
	}
	return 0;
}

