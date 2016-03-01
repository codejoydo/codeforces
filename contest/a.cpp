#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define SZ size
#define F first
#define S second
#define LL long long
#define II pair< int, int >

using namespace std;

int a[100005];
int main(){
	int n,m=0,l=1;
	cin >> n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	a[n]=0;
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			if(m<l)
				m=l;
			l=1;
		}
		else{
			l++;
		}
	}
	cout << m << endl;
	return 0;
}
