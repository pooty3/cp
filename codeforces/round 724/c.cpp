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
struct ar {
	vi arr;
	bool operator<(const ar &other) const {
		REP(i, arr.size()) {
			if (other.arr.size()==i) return false;
			if (other.arr[i]<arr[i]) return false;
			if (other.arr[i]>arr[i]) return true;
		}
		return true;
	}
	bool able(int x) const {
		return arr[arr.size()-1] == x;
	}
	void pr() const {
		REP(i, arr.size()) {
			cout<<arr[i];
			if (i+1==arr.size()) {
				cout<<"\n";
			} else {
				cout<<".";
			}
		}
	}
};
/*
void pr(const ar &a) {
	REP(i, a.arr.size()) {
		cout<<a.arr[i];
		if (i+1==a.arr.size()) {
			cout<<"\n";
		} else {
			cout<<".";
		}
	}
}*/
void solve() {
	int n;
	cin>>n;
	set<ar> ss;
	ar first = {{1}};
	ss.insert(first);
	REP(i, n) {
		int x;
		cin>>x;
		FOREACH(it, ss) {
			if (it->able(x)) {
				it->pr();
				vi narr = it->arr;
				vi narr2 = narr;
				narr2.push_back(1);
				narr[narr.size()-1]++;
				ss.insert({narr});
				ss.insert({narr2});
				ss.erase(ss.begin(), next(it));
				break;
			}
		}
	}

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