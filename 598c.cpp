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

const double PI=3.14159265;
struct pt{
	int index;
	double angle;
};
struct pt a[100005];

inline bool cmp(const struct pt& a,const struct pt& b){
	return a.angle<b.angle;
}

int main(){
	int n;
	si(n);
	for(int i=0;i<n;i++){
		double x,y;
		scanf("%lf %lf",&x,&y);
		a[i].index=i+1;
		if(x>=0&&y>=0){
			if(x==0){
				a[i].angle=PI/2.0;
			}
			else{
				a[i].angle=atan(y/x);
			}
		}
		else if(x<=0&&y>=0){
			x=-x;
			if(x==0){
				a[i].angle=PI/2.0;
			}
			else{
				a[i].angle=PI-atan(y/x);
			}
		}
		else if(x<=0&&y<=0){
			x=-x;
			y=-y;
			if(x==0){
				a[i].angle=(PI/2.0)*3;
			}
			else{
				a[i].angle=PI+atan(y/x);
			}

		}
		else if(x>=0&&y<=0){
			y=-y;
			if(x==0){
				a[i].angle=(PI/2.0)*3;
			}
			else{
				a[i].angle=2*PI-atan(y/x);
			}
		}
	}
	sort(a,a+n,cmp);
	double min=(2*PI-a[n-1].angle)+a[0].angle;
	int i1=a[0].index,i2=a[n-1].index;
	for(int i=0;i<n-1;i++){
		trace(a[i].angle,a[i+1].angle);
		printf("%.20lf\n",a[i+1].angle-a[i].angle);
		if(min>a[i+1].angle-a[i].angle){
			min=a[i+1].angle-a[i].angle;
			i1=a[i].index;
			i2=a[i+1].index;
		}
	}
	cout << i1 << ' ' << i2 << endl;
	return 0;
}
