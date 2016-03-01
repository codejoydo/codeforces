#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair< int, int >

using namespace std;

int main(){
	ll n;cin >>n;
	int cnt=0;
	while(n){
		if(n%2)cnt++;
		n/=2;
	}
	cout << cnt << endl;
	return 0;
}
