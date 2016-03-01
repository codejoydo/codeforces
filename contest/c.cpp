#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define SZ size()
#define F first
#define S second
#define LL long long
#define II pair< int, int >

using namespace std;

int n,m,s,d;
vector< int > v[100005];
int a[100005],vs[100005],cnt=0,mx=0,ans=0;

void dfs(int u){
	vs[u]=1;
	if(a[u]==1) cnt++;
	else cnt=0;
	mx = max(mx,cnt);
//	cout << u << ' '<< mx << endl;
	if(v[u].SZ==1 && mx <= m && u!=1){ 
		//		cout <<u<< mx << endl;
		ans++;
	} 
	int save= mx;
	int sv = cnt;
	//	cout << save << endl;
	for(int i=0;i<v[u].SZ;i++){
		mx=save;
		cnt=sv;
		if(u==1){ 
			mx=a[u]; 
			cnt=a[u];
		}
		int w = v[u][i];
		if(!vs[w])
			dfs(w);

	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&s,&d);
		v[s].PB(d);
		v[d].PB(s);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
