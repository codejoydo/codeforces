#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define FOR(i,lb,ub) for(i=lb;i<=ub;i++)
#define RFOR(i,ub,lb) for(i=ub;i>=lb;i--)
#define FORS(it,v) for(it=v.begin();it!=v.end();it++)
#define int long long
#define st_clk double st=clock();
#define end_clk double en=clock();
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
using namespace std;
void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;

	int bill = 0;
	int last = 0;

	for (int i=1; i<=n; i++) {
		if (s[i] == '(') {
			bill++;
		}
		else {
			if (s[i]=='#') {
				last = i;
			}
			bill--;
		}
	}

	//cout << bill << endl;

	if (bill<0) {
		cout << -1 << endl; 
		return;
	}

	int act = 0;
	for (int i=1; i<=n; i++) {
		if (s[i]=='(') {
			act++;
		}
		else {
			act--;
		}
		if (last == i) {
			act -= bill;
		}
		//cout << "act" << act << endl;
		if (act<0) {
        	cout << -1 << endl; 
			return;
		}
	}

	for (int i=1; i<=n; i++) {
		if (s[i]=='#') {
			cout << 1 + bill*(i==last)<<"\n";
		}
	}

}
main()
{
	st_clk
		ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,i,j;
	solve();

	return 0;
}
