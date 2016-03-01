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

double f(double x1, double y1, double x2, double y2, double pointX, double pointY)
{
	double diffX = x2 - x1; 
	float diffY = y2 - y1; 
	if ((diffX == 0) && (diffY == 0)){
		diffX = pointX - x1; 
		diffY = pointY - y1; 
		return sqrt(diffX * diffX + diffY * diffY);
	}   
	float t = ((pointX - x1) * diffX + (pointY - y1) * diffY) / (diffX * diffX + diffY * diffY);
	if (t < 0){ 
		diffX = pointX - x1; 
		diffY = pointY - y1; 
	}   
	else if (t > 1){ 
		diffX = pointX - x2; 
		diffY = pointY - y2; 
	}   
	else{
		diffX = pointX - (x1 + t * diffX);
		diffY = pointY - (y1 + t * diffY);
	}   
	return sqrt(diffX * diffX + diffY * diffY);
}

LL a,b,c;
int main(){
	LL x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if((x1==x2 and x2==x3) or (y1==y2 and y2==y3))
		cout<<1<<endl;
	else{
		if(x1==x2 or x3==x1 or x2==x3){
		 	if(x1==x2){ a=y1;b=y2;c=y3;}
		 	if(x3==x2){ a=y3;b=y2;c=y1;}
		 	if(x1==x3){ a=y1;b=y3;c=y2;}
			if(c==a or c==b) cout<<2<<endl;
			else if((c>a and c<b) or(c<a and c>b)) cout<<3<<endl;
			else if((c>a and c>b) or(c<a and c<b)) cout<<2<<endl;
		}
		else if(y1==y2 or y3==y1 or y2==y3){
			swap(x1,y1);
			swap(x2,y2);
			swap(x3,y3);
		 	if(x1==x2){ a=y1;b=y2;c=y3;}
		 	if(x3==x2){ a=y3;b=y2;c=y1;}
		 	if(x1==x3){ a=y1;b=y3;c=y2;}
			if(c==a or c==b) cout<<2<<endl;
			else if((c>a and c<b) or(c<a and c>b)) cout<<3<<endl;
			else if((c>a and c>b) or(c<a and c<b)) cout<<2<<endl;
			swap(x1,y1);
			swap(x2,y2);
			swap(x3,y3);
		}
		else{
			cout<<3<<endl;
		}
	}
	return 0;
}
