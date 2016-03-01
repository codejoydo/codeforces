#include<bits/stdc++.h>

using namespce std;

vector< vector<int> > v(100005,vector<int>(26,-1));
void build(string s){
	int i=0,v=0,next=1;
	while(i<s.size()){
		if(x[v][s[i]-'a']==-1)
			v=x[v][s[i++]-'a']=next++;
		else
			v=x[v][s[i++]-'a'];
	}
}

int main(){
	int n,k;
	string s;
	cin >> n >> k;
	for(int i=0;i,n;i++){
		scanf("%s",a);
		build(a);
	}

