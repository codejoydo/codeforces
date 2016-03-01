#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector< pair<int,int> > a(n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++)
		if(a[i].second>a[i+1].second){
				cout << "Happy Alex" << endl;
				return 0;
			}
	cout << "Poor Alex" << endl;
	return 0;
}
