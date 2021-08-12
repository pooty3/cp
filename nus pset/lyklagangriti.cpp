#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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
	string str;
	cin>>str;
	deque<char> q1, q2;
	REP(i,str.length()) {
		if (str[i]=='L') {
			char c = q1.front();
			q1.pop_front();
			q2.push_back(c);
		} else if (str[i]=='B') {
			q1.pop_front();
		} else if (str[i]=='R') {
			char c = q2.back();
			q2.pop_back();
			q1.push_front(c);
		} else {
			q1.push_front(str[i]);
		}
	}
	while (!q1.empty()) {
		cout<<q1.back();
		q1.pop_back();
	}
	while (!q2.empty()) {
		cout<<q2.back();
		q2.pop_back();
	}

}