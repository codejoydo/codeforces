#include<bits/stdc++.h>
using namespace std;
#define push_back pb
#define make_pair mp

int a[10004];
long long sum[11][10005];
int main(){
	int n,m,tp,q;
	char c;
	int p,l,r,mod;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);
	}
	for(int i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i]%m==j){
				sum[j][i]+=a[i];
			}
			sum[j][i]+=sum[j][i-1];
		}
	}
	cin >> q;
	while(q--){
		scanf("%c ",&c);
		if(c=='+'){
			scanf("%d %d",&p,&r);
			a[p-1]+=r;


		}
		else if(c=='-'){
			scanf("%d %d",&p,&r);
			s[a[p]].erase(s.find(mp(p,val[p])));
			if(val[p]-r>=0)
				val[p]-=r;
			s[val[p]%m].insert(mp(i,val[p]));
		}
		else if(c=='s'){
			scanf("%d %d %d",&l,&r,&mod);
			set<int>::iterator start=s.find(mp(l,val[l]));
			


			return 0;
		}
