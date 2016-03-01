#include<bits/stdc++.h>

using namespace std;

char s[300005],c;
int p[300005];
int root(int v){ return (p[v]<0)?(v):(p[v]=root(p[v]));}
void merge(int x,int y){
	if((x=root(x))==(y=root(y)))
		return;
	if(p[y]>p[x])
		swap(x,y);
	p[x]+=p[y];
	p[y]=x;
}

int main(){
	int n,q,ans=0,x; 
	cin >> n >> q;
	scanf("%s",s);
	for(int i=0;i<n+5;i++)
		p[i]=-1;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1] && s[i]=='.'){
			merge(i-1,i);
		}
	}
	for(int i=0;i<n;i++){
		if(p[i]<0&&p[i]!=-1)
			ans-=p[i]+1;
	}
	for(int i=0;i<q;i++){
		scanf("%d %c",&x,&c);
		x--;
		if(c=='.'&&s[x]!='.'){
			s[x]=c;
			if(s[x-1]=='.'&&x!=0)
				ans++;
			if(s[x+1]=='.'&&x!=n-1)
				ans++;
			cout << ans << endl;
		}
		else if(c!='.'&&s[x]=='.'){
			s[x]=c;
			if(s[x-1]=='.'&&x!=0)
				ans--;
			if(s[x+1]=='.'&&x!=n-1)
				ans--;			
			cout << ans << endl;
		}
		else{
			cout << ans << endl;
		}
	}

	return 0;
}


