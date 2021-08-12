#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
ll md = 1e9+7;
void solve() {
	vll pow2(200,1);
	REPL(i, 1, 200) {
		pow2[i] = pow2[i-1]*2;
		pow2[i]%=md;
	}
	int n;cin>>n;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vll arr1(60, 0);
	REP(i, n) {
		REP(j, 60) {
			if (arr[i]&(1LL<<j)) {
				arr1[j]++;
			}
		}
	}
	ll tot =0;
	REP(i, n) {
		vll parr1(60), parr2(60);
		REP(j, 60) {
			if(arr[i]&(1LL<<j)) {
				parr1[j] = arr1[j];
				parr2[j] = n;
			} else {
				parr1[j] = 0;
				parr2[j] = arr1[j];
			}
		}
		ll num1 =0, num2 =0;
		REP(j, 60) {
			num1+=(parr1[j]*pow2[j])%md;
			num1%=md;
		}
		REP(j, 60) {
			num2+= parr2[j]*pow2[j];
			num2%=md;
		}
		tot += (num1*num2)%md;
		tot%=md;
	}cout<<tot<<"\n";

}
map<ii, ld> cache;
ld findbest(int m, int n) {
	if (cache.find({m,n})== cache.end()) {
		if (n==0) {
			cache.insert({{m,n}, m});
		} else if (m==0) {
			cache.insert({{m,n}, 0});
		} else {
			cache.insert({{m,n}, max(0.0, (findbest(m-1,n)+1)/2 + (findbest(m,n-1)-1)/2 )});
		}
	}return cache[{m,n}];
} 
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	cout<<findbest(50,50);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}