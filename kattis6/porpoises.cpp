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

ll MOD = 1e9;

const int MAX_N = 2;                             // 2x2 for Fib matrix

struct Matrix { ll mat[MAX_N][MAX_N]; };         // we return a 2D array

ll mod(ll a, ll m) { return ((a%m)+m) % m; }     // ensure positive answer

Matrix matMul(Matrix a, Matrix b) {              // normally O(n^3)
  Matrix ans;                                    // but O(1) as n = 2
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      ans.mat[i][j] = 0;
  for (int i = 0; i < MAX_N; ++i)
    for (int k = 0; k < MAX_N; ++k) {
      if (a.mat[i][k] == 0) continue;            // optimization
      for (int j = 0; j < MAX_N; ++j) {
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD); // modular arithmetic
      }
    }
  return ans;
}

Matrix matPow(Matrix base, ll p) {              // normally O(n^3 log p)
  Matrix ans;                                    // but O(log p) as n = 2
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      ans.mat[i][j] = (i == j);                  // prepare identity matrix
  while (p) {                                    // iterative D&C version
    if (p&1)                                     // check if p is odd
      ans = matMul(ans, base);                   // update ans
    base = matMul(base, base);                   // square the base
    p >>= 1;                                     // divide p by 2
  }
  return ans;
}

void solve() {
	int tc;
	ll n;
	cin>>tc>>n;
	ll res;
	if (n==1||n==2) {
		res = 1;
	} else {
		Matrix m = {{{1,1}, {1,0}}};
		Matrix b = {{{1,1}, {0,0}}};
		res = matMul(matPow(m, n-1), b).mat[0][0];

	}
	cout<<tc<<" "<<res<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}