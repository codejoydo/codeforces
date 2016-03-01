#include<bits/stdc++.h>

using namespace std;

int dp[5005][5005];
int a[300005];
int main(){
	int n,k;
	int left,top;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int LMX=n%k,SMX=k-n%k,LSZ=n/k+1,SSZ=n/k;
	cout << LMX << ' ' << SMX << ' ' << LSZ << ' ' << SSZ << endl;
	for(int i=0;i<=SMX;i++){
		for(int j=0;j<=LMX;j++){
			cout << "____________________" << endl;
			cout << j << ' ' << i << endl;
			if(j && !i){
				left = a[j*LSZ+i*SSZ-1]-a[(j-1)*LSZ+i*SSZ];
				printf("*%d - %d*\n",j*LSZ+i*SSZ-1,(j-1)*LSZ+i*SSZ);
				printf("%d - %d\n",a[j*LSZ+i*SSZ-1],a[(j-1)*LSZ+i*SSZ]);
				left += dp[j-1][i];
				dp[j][i] = left;
			}
			else if(i && !j){
				top = a[i*SSZ+j*LSZ-1]-a[(i-1)*SSZ+j*LSZ];
				printf("*%d - %d*\n",j*LSZ+i*SSZ-1,j*LSZ+(i-1)*SSZ);
				printf("%d - %d\n",a[j*LSZ+i*SSZ-1],a[j*LSZ+(i-1)*SSZ]);
				top += dp[j][i-1];
				dp[j][i] = top;
			}
			else if(j && i){
				left = a[j*LSZ+i*SSZ-1]-a[(j-1)*LSZ+i*SSZ];
				cout << left << endl;
				left += dp[j-1][i];
				top = a[i*SSZ+j*SSZ-1]-a[(i-1)*SSZ+j*LSZ];
				cout << top << '=' << a[i*SSZ+j*LSZ] << '-' << a[(i-1)*SSZ+j*LSZ] << endl;
				top += dp[j][i-1];
				printf("*%d - %d*\n",j*LSZ+i*SSZ-1,(j-1)*LSZ+i*SSZ);
				printf("%d - %d\n",a[j*LSZ+i*SSZ-1],a[(j-1)*LSZ+i*SSZ]);
				printf("*%d - %d*\n",j*LSZ+i*SSZ-1,j*LSZ+(i-1)*SSZ);
				printf("%d - %d\n",a[j*LSZ+i*SSZ-1],a[j*LSZ+(i-1)*SSZ]);
				dp[j][i] = min(left,top);
			}
			cout << dp[j][i] << endl;
			cout << "____________________" << endl;
		}
	}
	cout << dp[LMX][SMX] << endl;
	return 0;
}

