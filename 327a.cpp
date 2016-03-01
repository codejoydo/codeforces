#include<bits/stdc++.h>

using namespace std;

/*int main(){
  vector<int> ar;
  int n,temp=0,max,a,one=0;
  cin >> n;
  ar.resize(n);
  for(int i=0;i<n;i++)
  cin >> ar[i];
  max=(ar[0])?(-1):(1);
  for(int i=0;i<n;i++){
  if(ar[i])
  one++;
  ar[i]=(ar[i])?(-1):(1);
  temp+=ar[i];
  if(temp>max)
  max=temp;
  if(temp<0)
  temp=0;
  }
  cout << max+one << endl;
  return 0;
  }*/

int dp[105][105];
int a[105];
int main(){
	int n,cnt1=0,cnt0=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		dp[i][i]=a[i]?0:1;
		a[i]?cnt1++:cnt0++;
	}
	for(int len=1;len<n;len++)
		for(int i=0;i<n-len;i++){
			int j=i+len;
//			cout << "----------------" << endl;
//			cout << j << ' ' << i << endl;
			dp[j][i]=dp[j-1][i]+dp[j][i+1]-dp[j-1][i+1];
//			cout << dp[j][i] << " = " << dp[j-1][i] << " + " << dp[j][i+1] << " - " << dp[j-1][i+1] << endl;
		}
	int ans,max=0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			ans=cnt1-(j-i+1-dp[j][i])+dp[j][i];
			if(max<ans)
				max=ans;
		}
	cout << max << endl;
	return 0;
}
