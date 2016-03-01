#include<bits/stdc++.h>

using namespace std;

int a[1000006];
set<long long> s;
int main(){
	a[0]=1;
	a[1]=1;
	int m = int(sqrt(1000006));
	for(int i=2;i<m;i++)
		if(!a[i])
			for(int j=i*i;j<1000006;j+=i)
				a[j]=1;
	for(long long i=0;i<1000006;i++)
		if(!a[i]){
//			cout << i*i << endl;
			s.insert(i*i);
		}
	long long foo,n;
	cin >> n;
	while(n--){
		cin >> foo;
		if(s.find(foo)!=s.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}


