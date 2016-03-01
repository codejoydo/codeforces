#include<bits/stdc++.h>

using namespace std;

int par[100005];

int root(int v){ return (par[v] == v) ? (v) : (par[v] = root(par[v])); }

void empt(int& x,int& y){
	int p=root(x);
	int q=root(y);
//	cout << p << ' ' << q << endl;
	par[p]=y;
	if(p==q)
		par[y]=y;
}

int main(){
	int n,q,a,b;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		par[i]=i;
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		empt(a,b);
	}
//	cout << "done" << endl;
	for(int i=1;i<=n;i++){
//		printf("%d ",par[i]);
		printf("%d ",root(i));
	}
	cout << endl;
	return 0;
}
