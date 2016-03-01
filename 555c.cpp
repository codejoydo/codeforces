#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k,m,count=0,part=0,tcount=0,fl,j;
	vector< vector<int> > a;
	cin >> n >> k;
	a.resize(k,vector<int>(0));
	for(int i=0;i<k;i++){
		cin >> m;
		a[i].resize(m);
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	}
	for(int i=0;i<k;i++){
		count=0;
		j=0;
		if(a[i][j]==1){
			for(j=0;j<a[i].size()-1;j++){
				if(a[i][j+1]==a[i][j]+1)
					continue;
				else
					break;
			}
		}
		count=a[i].size()-j-1;
		tcount+=count;
		part+=count+1;
//				cout << part << ' ' << count << endl;
	}
//		cout << tcount << endl;
//		cout << part << endl;
	cout << part-1+tcount << endl;
	return 0;
}

