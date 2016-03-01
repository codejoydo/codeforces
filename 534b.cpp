#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,t,d,ans=0,start;
	cin >> a >> b >> t >> d;
	ans=b;
	t--;
//	cout << a << endl;
	while(t--){
//		cout << "-------------------------" << endl;
//		cout << abs(b-a) << ' ' << (t+1)*d << endl;	
//		cout << "a=" << a << " ans=" << ans << endl;
		if(abs(b-a)<=(t+1)*d){
//			cout <<a<< " added" << endl;
			ans+=a;
			a+=d;
		}
		else{
//			cout << "else" << endl;
			a--;
			t++;
		}
	}
//	cout << b << endl;
	cout << ans << endl;		
	return 0;
}	
