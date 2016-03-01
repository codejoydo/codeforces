#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,k;
	string s;
	cin >> n >> s;
	for(i=0;i<n;i++)
		if(s[i]=='*')
			for(j=1;j<n;j++){
				for(k=0;k<5*j;k+=j){
					if(i+k<n){
						if(s[i+k]=='.')
							break;
//					cout << i+1 << ' ' << j+1 << ' ' << i+k+1 << endl;
					}
					else
						break;
				}
				if(k==5*j){
					cout << "yes" << endl;
					return 0;
				}
			}
	cout << "no" << endl;
	return 0;
}
