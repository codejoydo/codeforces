#include<bits/stdc++.h>

using namespace std;

/*int main(){
  int a,b,c,n,curr,max=0,ans;
  cin>>n>>a>>b>>c;
  if(a>b)swap(a,b);
  if(b>c)swap(b,c);
  if(a>b)swap(a,b);
  for(int i=0;i<n/b+3;i++)
  for(int j=0;j<n/b+3;j++){
  curr=n-b*i-c*j;
  if(curr>=0&&curr%a==0){
  ans=i+j+curr/a;
  if(max<ans)
  max=ans;
  }
  }
  cout<<max<<endl;
  return 0;
  }*/

int dp[100005];
int main(){
	int a,b,c,n,x,y,z;
	cin>>n>>a>>b>>c;
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	if(n-a>=0)dp[n]=1;
	for(int i=n-1;i>=0;i--){
		if(dp[i+a]||dp[i+b]||dp[i+c])
			dp[i]+=max(max(dp[i+a],dp[i+b]),dp[i+c])+1;
//		cout << i << ' ' << dp[i] << endl;
	}
	cout << dp[0]-1 << endl;
	return 0;
}
