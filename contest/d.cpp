#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define SZ size()
#define F first
#define S second
#define LL long long
#define II pair< int, int >

using namespace std;

int a[25],p[25],vs[25];
pair< II, int > b[625];
vector< pair< int, II > > v;
int main(){
	p[0]=1;
	for(int i=1;i<22;i++) p[i]=p[i-1]*2;
	int n,m,k,x,y,z;
	long long mx=0;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&x,&y,&z);
		b[i]=MP(MP(x,y),z);
	}
	for(int i=1;i<p[n];i++){
//		cout << "----" << endl;
		set<int> s;
		long long sum=0;
		int tp = i,cnt=0;
		for(int j=0;j<n;j++){
			if(tp%2){
				sum+=a[j];
				s.insert(j+1);
				cnt++;
//				cout << j+1 << ' ';
			}
			tp/=2;
		}
//		cout << endl;
		if(cnt>m)
			continue;
		v.clear();
		for(int j=0;j<k;j++){
			if(s.find(b[j].F.F)!=s.end() && s.find(b[j].F.S)!=s.end()){
				v.PB(MP(b[j].S,b[j].F));
//				cout << "yes" << endl;
			}
		}
		for(int j=0;j<=n;j++) vs[j]=0;
		sort(v.begin(),v.end());
		for(int j=v.SZ-1;j>=0;j--){
	//		if(!vs[v[j].S.F] && !vs[v[j].S.S]){
			if(!vs[v[j].S.S]){
				vs[v[j].S.F]=1;
				vs[v[j].S.S]=1;
				sum+=v[j].F;
//				cout << v[j].F << " added" << endl;
			}
		}
		mx=max(mx,sum);
	}
	cout << mx << endl;
	return 0;
}

