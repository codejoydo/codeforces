#include<bits/stdc++.h>

using namespace std;

#define pb push_back


int a[2005],check[2005];
vector<int> p,q;
int main(){
	for(int i=2;i<2005;i++)
		if(!a[i]){
		for(int j=i*i;j<2005;j+=i)
			a[j]=1;
		}
	for(int i=2;i<2005;i++)
		if(!a[i])
			p.pb(i);
	int n;
	cin >> n;
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	for(int i=0;;i++){
		if(p[i]>n)
			break;
		int ans=p[i];
		while(ans<=n){
			if(!check[ans]){
				check[ans]=1;
				q.pb(ans);
			}
			ans*=p[i];
		}
	}
	int m=q.size();
		cout << m << endl;
	for(int i=0;i<m;i++)
		printf("%d ",q[i]);
	cout << endl;

	return 0;
}
