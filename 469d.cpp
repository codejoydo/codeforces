#include<bits/stdc++.h>

using namespace std;

int n,a,b,cnt,typ,nn;
int p[100005],vs[100005],ans[100005];
set<int> v[100005];
map<int,int> m;
deque<int> q;

void dfs(int i, int side){
	vs[i]=1;

	if(v[i].size()==0)
		nn=1;
	if(v[i].size()==1){
		cnt++;
		if(p[*v[i].begin()]+p[i]==a)
			typ=0;
		else
			typ=1;
	}

	q.push_back(i);

	for(set<int>::iterator it=v[i].begin();it!=v[i].end();++it)
		if(!vs[*it]){
			if(p[*it]+p[i]==a)
				dfs(*it,0);
			else
				dfs(*it,1);
		}
}

int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		m[p[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(m[a-p[i]]) v[i].insert(m[a-p[i]]);
		if(m[b-p[i]]) v[i].insert(m[b-p[i]]);
		//	cout << i << " : " << m[a-p[i]] << ' ' << m[b-p[i]] << endl;
	}
	for(int i=1;i<=n;i++){
		if(!vs[i]){
			nn=0;
			typ=0;
			cnt=0;
			q.clear();
			dfs(i,0);
			if(nn){
				cout << "NO" << endl;
				return 0;
			}
			else if(cnt==0){
				for(deque<int>::iterator it=q.begin();it!=q.end();++it)
					ans[*it]=1;
			}
			else if(cnt==2){
				if(q.size()&1){
					cout << "NO" << endl;
					return 0;
				}
				else
					for(deque<int>::iterator it=q.begin();it!=q.end();++it)
						ans[*it]=typ;
			}
			else if(cnt==1){
				for(deque<int>::iterator it=q.begin();it!=q.end();++it)
					ans[*it]=typ;
			}
		}
	}
	cout << "YES" << endl;
	for(int i=1;i<=n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
