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
class SuffixArray {
private:
  vi RA;                                         // rank array

  void countingSort(int k) {                     // O(n)
    int maxi = max(300, n);                      // up to 255 ASCII chars
    vi c(maxi, 0);                               // clear frequency table
    for (int i = 0; i < n; ++i)                  // count the frequency
      ++c[i+k < n ? RA[i+k] : 0];                // of each integer rank
    for (int i = 0, sum = 0; i < maxi; ++i) {
      int t = c[i]; c[i] = sum; sum += t;
    }
    vi tempSA(n);
    for (int i = 0; i < n; ++i)                  // sort SA
      tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    swap(SA, tempSA);                            // update SA
  }

  void constructSA() {                           // can go up to 400K chars
    SA.resize(n);
    iota(SA.begin(), SA.end(), 0);               // the initial SA
    RA.resize(n);
    for (int i = 0; i < n; ++i) RA[i] = T[i];    // initial rankings
    for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
      // this is actually radix sort
      countingSort(k);                           // sort by 2nd item
      countingSort(0);                           // stable-sort by 1st item
      vi tempRA(n);
      int r = 0;
      tempRA[SA[0]] = r;                         // re-ranking process
      for (int i = 1; i < n; ++i)                // compare adj suffixes
        tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
          ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i]+k] == RA[SA[i-1]+k])) ?
            r : ++r;
      swap(RA, tempRA);                          // update RA
      if (RA[SA[n-1]] == n-1) break;             // nice optimization
    }
  }

  void computeLCP() {
    vi Phi(n);
    vi PLCP(n);
    PLCP.resize(n);
    Phi[SA[0]] = -1;                             // default value
    for (int i = 1; i < n; ++i)                  // compute Phi in O(n)
      Phi[SA[i]] = SA[i-1];                      // remember prev suffix
    for (int i = 0, L = 0; i < n; ++i) {         // compute PLCP in O(n)
      if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
      while ((i+L < n) && (Phi[i]+L < n) && (T[i+L] == T[Phi[i]+L]))
        ++L;                                     // L incr max n times
      PLCP[i] = L;
      L = max(L-1, 0);                           // L dec max n times
    }
    LCP.resize(n);
    for (int i = 0; i < n; ++i)                  // compute LCP in O(n)
      LCP[i] = PLCP[SA[i]];                      // restore PLCP
  }

public:
  const char* T;                                 // the input string
  const int n;                                   // the length of T
  vi SA;                                         // Suffix Array
  vi LCP;                                        // of adj sorted suffixes

  SuffixArray(const char* initialT, const int _n) : T(initialT), n(_n) {
    constructSA();                               // O(n log n)
    computeLCP();                                // O(n)
  }

  ii stringMatching(const char *P) {             // in O(m log n)
    int m = (int)strlen(P);                      // usually, m < n
    int lo = 0, hi = n-1;                        // range = [0..n-1]
    while (lo < hi) {                            // find lower bound
      int mid = (lo+hi) / 2;                     // this is round down
      int res = strncmp(T+SA[mid], P, m);        // P in suffix SA[mid]?
      (res >= 0) ? hi = mid : lo = mid+1;        // notice the >= sign
    }
    if (strncmp(T+SA[lo], P, m) != 0) return {-1, -1}; // if not found
    ii ans; ans.first = lo;
    hi = n-1;                                    // range = [lo..n-1]
    while (lo < hi) {                            // now find upper bound
      int mid = (lo+hi) / 2;
      int res = strncmp(T+SA[mid], P, m);
      (res > 0) ? hi = mid : lo = mid+1;         // notice the > sign
    }
    if (strncmp(T+SA[hi], P, m) != 0) --hi;      // special case
    ans.second = hi;
    return ans;                                  // returns (lb, ub)
  }                                              // where P is found

  ii LRS() {                                     // (LRS length, index)
    int idx = 0, maxLCP = -1;
    for (int i = 1; i < n; ++i)                  // O(n), start from i = 1
      if (LCP[i] > maxLCP)
        maxLCP = LCP[i], idx = i;
    return {maxLCP, idx};
  }

  ii LCS(int split_idx) {                        // (LCS length, index)
    int idx = 0, maxLCP = -1;
    for (int i = 1; i < n; ++i) {                // O(n), start from i = 1
      // if suffix SA[i] and suffix SA[i-1] came from the same string, skip
      if ((SA[i] < split_idx) == (SA[i-1] < split_idx)) continue;
      if (LCP[i] > maxLCP)
        maxLCP = LCP[i], idx = i;
    }
    return {maxLCP, idx};
  }
};


const int MAX_N = 450010;                        // can go up to 450K chars

char T[MAX_N];
char P[MAX_N];
char LRS_ans[MAX_N];
char LCS_ans[MAX_N];
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	string str;
	cin>>str;
	REP(i, str.size()) {
		T[i]= str[i];
	}
	T[n++] = '$';
	SuffixArray A(T, n);
	ii ans = A.LRS();
	printf("%d\n", ans.first);


}