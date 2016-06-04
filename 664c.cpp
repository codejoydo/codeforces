//joyneel
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int compare(string r,string bs){
	if(SZ(r)>SZ(bs) and r[0]>'0') return 1;
	if(SZ(r)<SZ(bs)) return 0;
	for(int i=0;i<SZ(r);i++){
		if(r[i]<bs[i]) return 0;
		else if(r[i]>bs[i]) return 1;
	}
	return 1;
}

string ss,s;
int ten[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ss;
		string s = "";
		for(int j=4;j<SZ(ss);j++){
			s = s + ss[j];
		}
		int base = 1989;
		for(int j=1;j<SZ(s);j++){
			base += ten[j];
		}
		string bs = to_string(base);
		if(compare(s,bs)){
			cout<<s<<endl;
			continue;
		}
		for(int j=1;j<=1000;j++){
			string r = to_string(j) + s;
			if(compare(r,bs) and SZ(r)>=SZ(bs)){
				cout<<r<<endl;
				break;
			}
		}	
	}
	return 0;
}
