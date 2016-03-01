#include<bits/stdc++.h>

using namespace std;

void dfs(const vector< vector<int> >& v,vector<int>& visit,int start){
	visit[start-1]=1;
	for(int i=0;i<v[start-1].size();i++)
		if(!visit[v[start-1][i]-1]){
			dfs(v,visit,v[start-1][i]);
		}
}

int main(){
	int n,nc=0;
	vector< pair<int,int> > a;
	vector< vector<int> > v;
	vector<int> visit;
	cin >> n;
	a.resize(n);
	v.resize(n);
	visit.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i].first >> a[i].second;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].first==a[j].first || a[i].second==a[j].second){
				v[i].push_back(j+1);
				v[j].push_back(i+1);
			}
	for(int i=0;i<n;i++){
		if(!visit[i]){	
			dfs(v,visit,i+1);
			nc++;
		}
	}
	cout << nc-1 << endl;
	return 0;
}
