#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<double> a;
	double n,w,ans,min1=1234567899,min2;
	scanf("%lf%lf",&n,&w);
	a.resize(2*n);	
	for(int i=0;i<2*n;i++){
		scanf("%lf",&a[i]);
		if(a[i]<min1)
			min1=a[i];
	}
	make_heap(a.begin(),a.end());
	for(int i=0;i<n-1;i++){
		pop_heap(a.begin(),a.end());
		a.pop_back();
	}
	min2=a[0];
//	cout << min1 << ' ' << min2;
	if(2*min1>min2)
		ans=(min2/2.0)*3*n;
	else
		ans=min1*3*n;
	if(ans<w)
		printf("%lf\n",ans);
	else
		printf("%lf\n",w);
	return 0;
}
