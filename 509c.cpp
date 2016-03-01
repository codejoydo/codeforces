#include<bits/stdc++.h>

using namespace std;

#define push_back pb

int pw[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int p=0;
vector<int> a;
int b[1005];

int main(){
	int n,b,prev=0;
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		if(i && b[i]<=b[i-1]){
			/* making digits of previous number*/
			int tp=b[i-1];
			while(tp){
				a.pb(tp%10);
				tp/=10;
			}
			int l=a.size();
			int s=b[i];

			if(a[l]>s){
				a.resize(l+1);
				a[0]=1;
				a[l]=s-1;
				for(int i=0;i<l+1;i++)
					cout << a[i];
				cout << endl;
				continue;
			}
			else{
				for(int i=l-1;i>=0;i--){
					if(s>a[i]){
						s-=a[i];
					}
					else{
						for(int j=i+1;j<l;j++){
							if(a[j]<9){
								a[j]++;
								s--;
								break;
							}
						}
						a[i]=s;
						for(int j=i-1;j>=0;j++)
							a[j]=0;
						break;
					}
				}
				sum=0;
				for(int i=l;i>=0;i--)
					cout << a[i];
				cout << endl;
			}
		}
		if(i==0 || b[i]>b[i-1]){
			int d=b[i]-b[i-1];
			for



			
