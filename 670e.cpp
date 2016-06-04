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
const int N = 500005;
string b,a;
int g[N],del[N],l[N],r[N];
stack<int> s;
int n,m,p;
int rem(int i){
	int p,q;
	p = q = i;
	del[i] = 1;
	int sum = (b[i]=='(') ? 1 : -1;
	while(sum){
		//trace(p,q);
		if(sum>0){
			q = r[q];
			if(b[q] == '(') sum++;
			else sum--;
		}
		else if(sum<0){
			p = l[p];
			if(b[p] == '(') sum++;
			else sum--;
		}
		del[p] = 1;
		del[q] = 1;
	}
	//trace(p,q);
	p = l[p];
	q = r[q];
	r[p] = q;
	l[q] = p;
	/*for(int i=0;i<n;i++){
		cout<<del[i]<<' ';
	}
	cout<<endl;*/
	if(del[p] and del[q]){
		return -1;
	}
	if(del[q]){
		r[p] = p;
	   	return p;
	}
	if(del[p]){
		l[q] = q;
	}
	return q;
}
int main(){
	si(n);si(m);si(p);
	cin>>b;
	cin>>a;
	for(int i=0;i<n;i++){
		if(i==0) l[i] = i;
		else l[i] = i-1;
		if(i==n-1) r[i] = i;
		else r[i] = i+1;
	}
	for(int i=0;i<n;i++){
		if(b[i] == '(')
			s.push(i);
		else{
			g[i] = s.top();
			g[s.top()] = i;
		}
	}
	int curr = p-1;
	for(int i=0;i<m;i++){
		if(a[i] == 'D'){
			curr = rem(curr);
			if(curr == -1) break;
		}
		else if(a[i] == 'L'){
			curr = l[curr];
		}
		else if(a[i] == 'R'){
			curr = r[curr];
		}
	}
	for(int i=0;i<n;i++){
		if(!del[i]) putchar(b[i]);
	}
	cout<<endl;
	return 0;
}
