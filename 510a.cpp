#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	for(int i=0;i<a;i++){
		if(i&1){
			if(i&2){
				cout << '#';
				for(int i=0;i<b-1;i++)
					cout << '.';
			}
			else{
				for(int i=0;i<b-1;i++)
					cout << '.';
				cout << '#';
			}
		}
		else
			for(int i=0;i<b;i++)
				cout << '#';
		cout << endl;
	}
	return 0;
}

