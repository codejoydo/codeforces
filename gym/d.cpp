#include<bits/stdc++.h>

using namespace std;
#define push_back pb

int main(){
	int n,tp;
	cin >> n;
	long long ans=0;	
	for(int i=0;i<n;i++){
		scanf("%d",&tp);
		long long j=(long long)ans^(long long)tp;
		ans = j;
	}
	cout << ans << endl;
	return 0;
}
