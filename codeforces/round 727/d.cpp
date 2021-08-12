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
typedef pair<ll, ll> llll;
typedef double ld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vector<llll> vec(n);
	REP(i, n) {
		ll a, b;
		cin>>a>>b;
		vec[i] = {b,a};
	}
	SORT(vec);
	int done = 0;
	int curhgh = n-1;
	int curlw = 0;
	ll curamt = 0;
	ll cura = 0;
	while (true) {
		if (cura < vec[curlw].first) {
			ll tominus = min(vec[curhgh].second, vec[curlw].first-cura);
			vec[curhgh].second -= tominus;
			cura += tominus;
			curamt += tominus*2;
			if (vec[curhgh].second == 0) {
				done++;
				curhgh--;
			}
		} else {
			cura += vec[curlw].second;
			curamt += vec[curlw].second;
			vec[curlw].second =0;
			done ++;
			curlw ++;
		} if (done == n) break;
	}
	cout<<curamt;
}