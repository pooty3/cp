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

void solve(int zz) {
	int n,q;
	cin>>n>>q;
	map<int, int> mp;
	REP(i, n) {
		string str;
		int s;
		cin>>str>>s; int cur =0;
		REP(i, q) {
			if (str[i] == 'T') cur += (1<<i);
		}
		mp.insert({cur, s});
	}
	vi pos;
	REP(i, (1<<q)) {
		bool valid = true;
		for (auto &[cstr, c]: mp) {
			int sc =0;
			REP(j, q) {
				int ct = cstr&(1<<j);
				int ct2 = i&(1<<j);
				if ((ct == 0 && ct2 == 0 )||(ct!=0 && ct2!= 0))	{
					sc ++;
				}		
			}
			if (sc != c) {
				valid = false;break;
			}
		}
		if (valid) {
			pos.push_back(i);
		}
	}
	vi arr(q, 0);
	int score =0;
	REP(i, q) {
		int Tscore=0;
		for (int zz: pos) {
			if (zz&(1<<i)) {
				Tscore ++;
			}

		}
		if (Tscore > pos.size()/2) {
			arr[i] = 1;
			score += Tscore;
		} else {
			score += (pos.size()-Tscore);
		}
	}
	string str;
	REP(i, q) {
		str += arr[i] == 1 ? 'T' : 'F';
	}
	int num = score / __gcd(score, (int)pos.size());
	int dem = (int)pos.size()/ __gcd(score, (int)pos.size());
	cout<<"Case #"<<zz<<": "<<str<<" "<<num<<"/"<<dem<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}