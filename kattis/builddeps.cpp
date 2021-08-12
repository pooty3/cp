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

bool visited[100001];
void toposort(vvi &adj, int i, stack<int> &s) {
	if (!visited[i]) {
		visited[i] = true;
		FOREACH(it, adj[i]) {
			toposort(adj, *it, s);
		}
		s.push(i);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	int cur = 0;
	unordered_map<string, int> mp(n);
	vector<string> arr(n);
	vvi adj (n, vi());
	string str;
	getline(cin, str);
	REP(i, n) {
		getline(cin, str);
		stringstream s(str);
		s>>str;
		str = str.substr(0, str.length()-1);
		if (mp.find(str)==mp.end()) {
			mp.insert({str, cur});
			arr[cur] = str;
			cur++;
		}
		int ind = mp[str];
		while (s>>str) {
			if (mp.find(str)==mp.end()) {
				mp.insert({str, cur});
				arr[cur] = str;
				cur++;
			}
			int ind2 = mp[str];
			adj[ind2].push_back(ind);
		}

	}
	cin>>str;
	stack<int> s;
	toposort(adj, mp[str], s);
	while (!s.empty()) {
		cout<<arr[s.top()]<<"\n";
		s.pop();
	}

	

}