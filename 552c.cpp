#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,tp;
	vector< int > santa;
	cin >> a >> b;
	tp=b;
	while(tp>0){
		santa.push_back(tp%a);
		tp/=a;
	}
	santa.push_back(0);
	for(int i=0;i<santa.size()-1;i++){
		if(santa[i]>1){
			santa[i+1]++;
			santa[i]-=a;
		}
//		cout << santa[i] << ' ' <<  santa[i+1] << endl;
		if(santa[i]<-1||santa[i]>1){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}

