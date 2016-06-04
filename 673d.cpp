//joyneel
#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int m[1001];
int main(){
	int n,k,a,b,c,d;
	cin>>n>>k>>a>>b>>c>>d;
	m[a]=m[b]=m[c]=m[d]=1;
	if(n==4 or k<=n) cout<<-1<<endl;	
	else{
		cout<<a<<' '<<c<<' ';
		for(int i=n;i>=1;i--) if(!m[i]) cout<<i<<' ';
		cout<<d<<' '<<b<<endl;
		cout<<c<<' '<<a<<' ';
		for(int i=n;i>=1;i--) if(!m[i]) cout<<i<<' ';
		cout<<b<<' '<<d<<endl;
	}
	return 0;
}
