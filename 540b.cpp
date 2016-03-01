#include<bits/stdc++.h>

using namespace std;

int a[1005];
vector<int> b,c,d;
int main(){
	int n,k,p,x,y,sum=0,left,right;
	cin >> n >> k >> p >> x >> y;
	for(int i=0;i<k;i++){
		cin >> a[i];
		sum+=a[i];
	}
	for(int i=k;i<n;i++){
		a[i]=1;
		sum++;
	}
	int test=n-k+1,cnt=n-k;
	while(test--){
		sort(a,a+n);
		if(sum>x){
			cout << -1 << endl;
			return 0;
		}
		if(a[n/2]<y){
			a[0]=y;
			b.push_back(y);
			cnt--;
			sum+=y-1;
		}
		else{
			for(int i=0;i<cnt;i++)
					cout << 1 << endl;
			for(int i=0;i<b.size();i++)
					cout << b[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
