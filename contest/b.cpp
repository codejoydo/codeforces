#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define SZ size
#define F first
#define S second
#define LL long long
#define II pair< int, int >

using namespace std;

II a[100005];
deque< II > q;
int main(){
	int n,d,m,s;
	cin >> n >> d;
	for(int i=0;i<n;i++){
		scanf("%d %d",&m,&s);
		a[i]=MP(m,s);
	}
	int l=0,r=0;
	long long f = 0, mx = 0;
	sort(a,a+n);
	q.PB(a[0]);
	int j=0;
	while(a[0].F+d > a[r].F && r<n){
		q.PB(a[r]);
		f += a[r].S;
		r++;
	}
	while(r<n){
		if(mx < f)
			mx = f;
		q.pop_front();
		f -= a[l].S;
		l++;
		while(a[l].F+d>a[r].F && r<n){
			q.PB(a[r]);
			f += a[r].S;
			r++;
		}
	}
	if(mx < f)
		mx = f;
	cout << mx << endl;

	return 0;
}
