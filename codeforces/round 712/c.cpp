#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999999
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	ll curtot =0;
	ll curlw = 0;	
	ll curlwA = INF;
	cin>>n;
	vll aarr(n);
	vll caarr(n);
	REP(i, n) {
		ll a,c;
		cin>>a>>c;
		curtot += c;
		aarr[i] = a;
		caarr[i] = a+c;
		if (curlwA > aarr[i]) {
			curlwA = aarr[i];
			curlw = caarr[i];
		}
	}
	set<pair<ll, int>> inacc;
	ll nable=curlw;
	REP(i, n) {
		if (aarr[i] > curlw) {
			inacc.insert({aarr[i], i});
		} else {
			nable = max(nable, caarr[i]);
		}
	}
	while (!inacc.empty()) {
		if (nable == curlw) {
			auto &[aa,ind] = *inacc.begin();
			curtot += (aa-curlw);
			curlw = caarr[ind];
		} else {
			curlw = nable;
		}
		int toremove =0;
		FOREACH(it, inacc) {
			if (it ->first > curlw) {
				break;
			} else {
				int ind = it->second;
				nable = max(nable, caarr[ind]);
				toremove++;
			}
		}
		REP(i, toremove) {
			inacc.erase(inacc.begin());
		}
	}
	cout<<curtot;

}