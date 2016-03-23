#include <bits/stdc++.h>
// #include "testlib.h"	
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const int maxn = 1e5 + 15;
const int mod = 1e9 + 7;

int ADD(int a, int b, int m = mod) {
	int s = a;
	s += b;
	if( s >= m )
		s -= m;
	return s;
}

int MUL(int a, int b, int m = mod) {
	return (1LL * a * b % m);
}


int power(int a, int b, int m = mod) {
	int res = 1;
	while( b ) {
		if( b & 1 ) {
			res = 1LL * res * a % m;
		}
		a = 1LL * a * a % m;
		b /= 2;
	}
	return res;
}

ll nC2(ll x) {
	return ( x * ( x - 1 ) / 2 );
}

int A[ maxn ];

class BIT_PointUpdateRangeQuery {
	public:
		BIT_PointUpdateRangeQuery( int n ) {
			sz = n;
			BIT.resize( sz+1 );
			fill( BIT.begin(), BIT.end(), 0 );
		}
		void Update( int idx, long long int val ) {
			while( idx <= sz ) {
				BIT[idx] += val;
				idx += idx & -idx;
			}
		}
		long long int Query( int idx ) {
			long long int sum = 0;
			while( idx ) {
				sum += BIT[idx];
				idx -= idx & -idx;
			}
			return sum;
		}
		long long int RangeQuery( int l, int r ) {
			if( l > r ) return 0;
			return (Query(r) - Query(l-1));
		}
	private:
		vector<long long int> BIT;
		int sz;
};
int main() {
	int n, k;
	cin >> n >> k;
	int i, l, r;
	fr(i, 1, n) A[i] = i;
	l = 1; r = n;
	while( k && l <= r ) {
		swap(A[l], A[r]);
		l ++; r --;
		k --;
	}
	ll ans = 0;
	BIT_PointUpdateRangeQuery bit(n);
	fr(i, 1, n) {
		ans += bit.RangeQuery(A[i]+1, n);
		bit.Update(A[i], 1);
	}
	cout << ans << "\n";		
	return 0;
}
