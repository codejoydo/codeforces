#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define S second
#define F first

using namespace std;

vector< pair<int,int> >  v[888];
int p[888],vs[888],ans[888];
int main(){
	int n,tp;
	cin >> n;
	int cnt=2*n;
	for(int i=2;i<=2*n;i++)
		for(int j=1;j<=i-1;j++){
			scanf("%d",&tp);
			v[i].pb(mp(tp,j));
			v[j].pb(mp(tp,i));
		}
	for(int i=1;i<=2*n;i++){
		sort(v[i].begin(),v[i].end());
		p[i]=2*n-2;
	}
	while(cnt){
		for(int j=1;j<=2*n;j++){
			if(!vs[j]){
				int id=v[j][p[j]].S;
				if(vs[id])
					p[j]--;
				if(v[id][p[id]].S==j){
					ans[j]=id;
					ans[id]=j;
					vs[j]=1;
					vs[id]=1;
					cnt-=2;
				}
			}
		}
	}
	for(int i=1;i<=2*n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
