#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,l,r,x,sum,max,min,temp,ans=0;
	vector<int> bin,a,b;
	cin >> n >> l >> r >> x;
	a.resize(n);
	bin.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<int(pow(2.0,double(n)));i++){
		b.clear();
		temp=i;
		sum=0;
		max=0;
		min=INT_MAX;
		for(int j=0;j<n;j++){
			if(temp%2==1){
				if(a[j]>max)
					max=a[j];
				if(a[j]<min)
					min=a[j];
				sum+=a[j];
			}
			temp/=2;
		}
		if(l<=sum && sum<=r && max-min>=x)
			ans++;
	}
	cout << ans << endl;
	return 0;
}	
