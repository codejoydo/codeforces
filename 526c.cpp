#include<bits/stdc++.h>

using namespace std;

int main(){
	int c,h1,h2,w1,w2;
	int ans,m,l,temp;
	cin >> c >> h1 >> h2 >> w1 >> w2;
	ans=(h1>h2)?(h1*(c/w1)):(h2*(c/w2));
	rem=(h1>h2)?(c-w1*(c/w1)):(c-w2*(c/w2));
	m=(h1>h2)?(w1):(w2);
	l=(h1>h2)?(w2):(w1);
	ans+=rem*(rem/l);
	rem=rem%l;
	temp=ans;
	for(;;){
		temp+=-1*

