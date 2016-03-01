#include<bits/stdc++.h>

using namespace std;

int cnt[1005];
int main(){
	int n,tp,s,ans=0,max=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> tp;
		if(max<tp)
			max=tp;
		if(i==0)
			s=tp;
		cnt[tp]++;
	}
	if(s==max && cnt[s]==1){
		cout << ans << endl;
		return 0;
	}
	while(max>0){
		if(cnt[max]){
//			cout << s << ' ' << max << endl;
			int i;
			int n=cnt[max];
			for(i=1;i<=n;i++){
				if(s>max){
					cout << ans << endl;
					return 0;
				}
				s++;
				cnt[max]--;
				cnt[max-1]++;
				ans++;
			}
			if(cnt[max]<=0)
				max--;

		}
	}
	cout << ans << endl;
	return 0;
}


