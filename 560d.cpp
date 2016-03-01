#include<bits/stdc++.h>

using namespace std;

char a[200005],b[200005];
int solve(string l,string r){
	int n=l.length();
	int mid=n/2;
	if(n&1){
		for(int i=0;i<l.length();i++){
			if(l[i]!=r[i]){
				return 0;
				break;
			}
		}
		return 1;
	}
	else{
		int x=solve(l.substr(0,n/2),r.substr(0,n/2))&&solve(l.substr(mid,n/2),r.substr(mid,n/2));
		int y=solve(l.substr(0,n/2),r.substr(mid,n/2))&&solve(l.substr(mid,n/2),r.substr(0,n/2));
		return x||y; 
	}
}


int main(){
	int l,ans;
	scanf("%s%s",a,b);
	l=a.length();
	ans=solve(a,b);
	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
