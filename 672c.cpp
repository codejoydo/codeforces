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

//#define TRACE

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
double dist(double a,double b,double c,double d){
	double aa = (c-a)*(c-a);
	double bb = (d-b)*(d-b);
	return sqrt(aa+bb);
}
double ans = 0;
vector<pair<double,double>> t;
vector<pair<double,int>> va,vb;
int m[100005];
int main(){
	double ax,ay,bx,by,tx,ty;
	scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&tx,&ty);	
	int n;
	si(n);
	for(int i=0;i<n;i++){
		double x,y;
		scanf("%lf %lf",&x,&y);
		t.PB({x,y});
	}
	for(int i=0;i<n;i++){
		double x = t[i].F;
		double y = t[i].S;
		va.PB({{dist(ax,ay,x,y)-dist(tx,ty,x,y)},i});
		vb.PB({{dist(bx,by,x,y)-dist(tx,ty,x,y)},i});
	}
	sort(ALL(va));
	sort(ALL(vb));
	for(int i=0;i<n;i++){
		double x = t[i].F;
		double y = t[i].S;
		double dt = dist(x,y,tx,ty);
		ans += dt + dt;
	}
	if(n==1){
		ans += min(va[0].F,vb[0].F);
		printf("%.12lf\n",ans);
		return 0;
	}
	trace(ans,va[0].F,va[0].S,vb[0].F,vb[0].S);
	m[va[0].S] = 1;
	double ans1 = ans+va[0].F;
	for(int i=0;i<n;i++){
		int j = vb[i].S;
		if(m[j]) continue;
		if(vb[i].F=0){
			ans1 = min(ans1,ans1+vb[i].F);
			trace(vb[i].F,i,j);
			break;
		}
	}
	m[va[0].S] = 0;
	m[vb[0].S] = 1;
	double ans2 = ans+vb[0].F;
	for(int i=0;i<n;i++){
		int j = va[i].S;
		if(m[j]) continue;
		if(va[i].F<0){
			ans2 = min(ans2,ans2+va[i].F);
			trace(va[i].F,i,j);
			break;
		}
	}
	ans = min(ans1,ans2);
	printf("%.12lf\n",ans);
	return 0;
}
