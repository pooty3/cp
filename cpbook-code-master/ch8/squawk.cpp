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
ll MOD = 1e18;

const int MAX_N = 100;                             // 2x2 for Fib matrix

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

Matrix matPow(Matrix base, int p) {              // normally O(n^3 log p)
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	if (t==0) {
		cout<<0; return 0;
	}
	Matrix b;
	REP(i, 100) {
		REP(j, 100) {
			b.mat[i][j] = 0;
		}
	}
	REP(i, m){
		int u,v;
		cin>>u>>v;
		b.mat[u][v] =1;
		b.mat[v][u] = 1;
	}
	Matrix final = matPow(b, t);
	ll tot =0;
	REP(i, 100) {
		tot += final.mat[s][i];

	}cout<<tot;
}