#include<bits/stdc++.h>

using namespace std;

int rt;

int sc(const vector< vector<int> >& v, vector<int>& visit, vector<int>& arr, int start, int& time){
	int xyz;
	arr[start-1]=time++;
	visit[start-1]=1;
	xyz=arr[start-1];
	for(int i=0;i<v[start-1].size();i++){
		if(!visit[v[start-1][i]-1]){
//			cout << v[start-1][i] << " visited\n";
			xyz=min(xyz,sc(v,visit,arr,v[start-1][i],time));
		}
		else{
//			cout << v[start-1][i] << " re-visited\n";
			xyz=min(xyz,arr[v[start-1][i]-1]);
		}
	}
	if(start!=rt)
		if(xyz==arr[start-1])
			return -1;
//	cout << xyz << endl;
	return xyz;
}

int main(){
	int n,m,time=0,nc=0;
	vector<char> h,v;
	vector<int> visit,arr;
	vector< vector<int> > a;
	cin >> n >> m;
	h.resize(n);
	v.resize(m);
	visit.resize(m*n);
	arr.resize(m*n);
	a.resize(m*n);
	for(int i=0;i<n;i++)
		cin >> h[i];
	for(int i=0;i<m;i++)
		cin >> v[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
//			cout  << "i=" << i << ' ' << "j=" << j << ' ' <<  m*i+j+1 << ' ' << h[i] << ' ' << v[j] << endl;
			if(h[i]=='<'){
				if(j>0)
					a[m*i+j].push_back(m*i+j);
			}
			else
				if(j<m-1)
					a[m*i+j].push_back(m*i+j+2);
			if(v[j]=='^'){
				if(i>0)
					a[m*i+j].push_back(m*(i-1)+j+1);
			}
			else
				if(i<n-1)
					a[m*i+j].push_back(m*(i+1)+j+1);
		}
//	for(int i=0;i<m*n;i++){
//		cout << i+1 << " : ";
//		for(int j=0;j<a[i].size();j++)
//			cout << a[i][j] << ' ';
//		cout << endl;
//	}
	for(int i=0;i<m*n;i++){
		if(!visit[i]){
			nc++;
			rt=i+1;
			if(sc(a,visit,arr,rt,time)==-1){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if(nc>1)
		cout << "NO" << endl;
	else if(nc==1)
		cout << "YES" << endl;
	
	return 0;
}

