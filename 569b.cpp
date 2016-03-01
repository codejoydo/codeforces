#include<bits/stdc++.h>

using namespace std;

deque<int> q;
int a[100005],c[100005];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]<=n)
			c[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
		if(!c[i])
			q.push_front(i);
	for(int i=0;i<n;i++){
		if(c[a[i]]!=2&&c[a[i]]==1){
			printf("%d ",a[i]);
			c[a[i]]=2;
		}
		else{
			printf("%d ",q.front());
			q.pop_front();
		}
	}
	cout << endl;
	return 0;
}


