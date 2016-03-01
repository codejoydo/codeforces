#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,s,q,time=0,cnt=0;
	cin >> t >> s >> q;
	for(time=0;s<t;time++){
		if(time>s){
			cnt++;
			time=0;
		}
		if(time%q)
			s+=q-1;
		if(time>s){
			cnt++;
			time=0;
		}
//		cout << s << ' ' << time << endl;		
	}
	cout << cnt+1 << endl;
	return 0;
}
			
