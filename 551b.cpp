#include<bits/stdc++.h>

using namespace std;

int main(){
	int nb,nc,tp,mnb,mnc,max=0;
	string a,b,c;
	vector<int> p(26),q(26),r(26),s(26);
	cin >> a >> b >> c;
	for(int i=0;i<a.length();i++)
		p[a[i]-'a']++;
	for(int i=0;i<b.length();i++)
		q[b[i]-'a']++;
	for(int i=0;i<c.length();i++)
		r[c[i]-'a']++;
	nb=100005;
	for(int i=0;i<26;i++){
		tp=100005;
		if(q[i])
			if(p[i]>=q[i])
				tp=p[i]/q[i];
			else{
				nb=0;
				break;
			}
		if(nb>tp)
			nb=tp;
	}
	for(int j=0;j<=nb;j++){
		for(int i=0;i<26;i++)
			s[i]=p[i]-j*q[i];
		nc=100005;
		for(int i=0;i<26;i++){
			tp=100005;
			if(r[i])
				if(s[i]>=r[i])
					tp=s[i]/r[i];
				else{
					nc=0;
					break;
				}
			if(nc>tp)
				nc=tp;
		}
//		cout << j << ' ' << nc << endl;
		if((j+nc)>max){
			max=j+nc;
			mnb=j;
			mnc=nc;
		}
		else if((j+nc)<max)
			break;
	}
	for(int i=0;i<26;i++)
		p[i]-=mnb*q[i]+mnc*r[i];
	for(int i=0;i<mnb;i++)
		cout << b;
	for(int i=0;i<mnc;i++)
		cout << c;
	for(int i=0;i<26;i++)
		for(int j=0;j<p[i];j++)
			cout << char(i+'a');
	cout << endl;
	return 0;
}
