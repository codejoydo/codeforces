#include<bits/stdc++.h>

using namespace std;

void bfs(vector< vector<int> >& v,vector<int>& visited,vector<int>& level,int start){
	int u;
	deque<int> queue;
	level[start-1]=1;
	visited[start-1]=1;
	queue.push_back(start);
	while(!queue.empty()){
		u=queue.front();
		for(int i=0;i<v[u-1].size();i++){
			if(!visited[v[u-1][i]-1]){
				visited[v[u-1][i]-1]=1;
				level[v[u-1][i]-1]=level[u-1]+1;
				queue.push_back(v[u-1][i]);
			}
		}
		queue.pop_front();
	}
}

int main(){
	int t,p,max=0;
	vector< vector<int> > v;
	vector<int> visited,level,a;
	cin >> t;
	v.resize(t+5);
	visited.resize(t+5);
	level.resize(t+5);
	for(int i=0;i<t;i++){
		cin >> p;

		a.push_back(p);
		if(p!=-1)
			v[p-1].push_back(i+1);
	}
	for(int i=0;i<t;i++){
		if(!(visited[i]) && a[i]==-1)
			bfs(v,visited,level,i+1);
	}
	for(int i=0;i<t;i++)
		if(level[i]>max)
			max=level[i];
	cout << max << endl;
	return 0;
}

