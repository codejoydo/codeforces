#include<bits/stdc++.h>

using namespace std;
#define pb push_back

vector<long long> sr,sb;
long long pw[20];
int r[20],b[20],bin[20];
int main(){
	pw[0]=1;
	for(int i=1;i<20;i++){
		pw[i]=2*pw[i-1];
	}
	int m,n;
	cin >> m >> n;
	for(int i=0;i<m;i++)
		scanf("%d",&r[i]);	
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);

	for(int i=1;i<pw[m];i++){	
		int tp=i;
		for(int j=0;j<m;j++){
			bin[j]=tp%2;
			tp/=2;
		}
		long long sum=0;
		for(int j=0;j<m;j++){
			if(bin[j])
				sum+=r[j];
		}
		sr.pb(sum);
	}
	for(int i=1;i<pw[n];i++){	
		int tp=i;
		for(int j=0;j<n;j++){
			bin[j]=tp%2;
			tp/=2;
		}
		long long sum=0;
		for(int j=0;j<n;j++){
			if(bin[j])
				sum+=b[j];
		}
		sb.pb(sum);
	}
	long long cnt=0;
	// O(n2)
	int lr=sr.size(),lb=sb.size();
	for(int i=0;i<lr;i++){
		for(int j=0;j<lb;j++){
			if(sr[i]==sb[j]){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
