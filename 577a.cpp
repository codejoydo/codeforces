#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int main(){
	int a,b,cnt=0;
	cin >> a >> b;
	for(int i=1;i<=a;i++){
		if(b%i==0 && b/i<=a){
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}
