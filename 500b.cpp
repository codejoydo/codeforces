#include<bits/stdc++.h>

using namespace std;

void bfs(vector< deque<int> >& v,vector<int>& visit,int start,int& label){
	int u;
	deque<int> q;
	visit[start-1]=label;
	q.push_back(start);
	while(!q.empty()){
			u=q.front();
			for(int i=0;i<v[u-1].size();i++)
				if(!visit[v[u-1][i]-1]){
					visit[v[u-1][i]-1]=label;
					q.push_back(v[u-1][i]);
				}
			q.pop_front();
	}
	label++;
}

int main(){
	char num;
	int n,cno=1;
	vector<int> index,a,visit;
	vector< deque<int> > v;
	cin >> n;
	index.resize(n);
	v.resize(n);
	a.resize(n);
	visit.resize(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		index[a[i]-1]=i;
	}	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin >> num;
			if(num-'0'){
				v[j].push_back(i+1);
				v[i].push_back(j+1);
			}
		}
	for(int i=0;i<n;i++)
		if(!visit[i])
			bfs(v,visit,i+1,cno);
	v.clear();
	v.resize(n);
	for(int i=0;i<n;i++)
		v[visit[i]-1].push_back(a[i]);
	for(int i=0;i<n;i++)
		sort(v[i].begin(),v[i].end());
	for(int i=0;i<n;i++){
		a[i]=v[visit[i]-1].front();
		v[visit[i]-1].pop_front();
	}
	for(int i=0;i<n;i++)	
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
