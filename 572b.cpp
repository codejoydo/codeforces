#include<bits/stdc++.h>

using namespace std;

map<int,int> a,b;
vector<pair<int,int> > m,n;
int main(){
	char c[3];
	int q,d,cost,qty;
	cin >> q >> d;
	for(int i=0;i<q;i++){
		scanf("%s %d %d",c,&cost,&qty);
		if(c[0]=='S')
			a[cost]+=qty;
		else if(c[0]=='B')
			b[cost]+=qty;
	}
	for(map<int,int>::iterator it=a.begin();it!=a.end();it++)
		m.push_back(make_pair(it->first,it->second));
	for(map<int,int>::iterator it=b.begin();it!=b.end();it++)
		n.push_back(make_pair(it->first,it->second));
	sort(m.begin(),m.end());
	sort(n.begin(),n.end());
	int start;
	if(d>m.size())
		start = m.size()-1;
	else
		start = d-1;
	for(int j=start;j>=0;j--){
		if(j>m.size()-1)
			break;
		printf("S %d %d\n",m[j].first, m[j].second);
	}
	int i=n.size()-1;
	for(int j=0;j<d;j++){
		if(i-j<0)
			break;
		printf("B %d %d\n",n[i-j].first, n[i-j].second);
	}
	return 0;
}

