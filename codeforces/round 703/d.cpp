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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ost;

int findmed(vii &arr, int k, int n) {
	ost tree;
	REP(i, k) {
		tree.insert(arr[i]);
		//tree2.insert(arr2[i]);
	}
	int curmed = tree.find_by_order((tree.size()+1)/2 - 1) -> first;
	int bk = 0;
	int maxmed = curmed;
	REPL(i, k, n) {
		if (arr[bk].first < curmed) {
			tree.erase(tree.find({arr[bk]}));
			bk++;
		}
		tree.insert(arr[i]);
		curmed = tree.find_by_order((tree.size()+1)/2 -1) -> first;
		maxmed = max(curmed, maxmed);
		while (arr[bk].first < curmed && i-bk+1 > k) {
			tree.erase(tree.find({arr[bk]}));
			bk++;
			curmed = tree.find_by_order((tree.size()+1)/2-1) -> first;
			maxmed = max(curmed, maxmed);
		}
	}
	return maxmed;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	vii arr(n);
	REP(i, n) {
		int x;
		cin>>x;
		arr[i] = {x,i};
	}
	ost tree, tree2;
	REP(i, k) {
		tree.insert(arr[i]);
	}
	int curmed = tree.find_by_order((tree.size()+1)/2 - 1) -> first;
	int maxmed = curmed;
	REPL(i, k, n) {
		tree.erase(tree.find(arr[i-k]));
		tree.insert(arr[i]);
		maxmed = max(maxmed, tree.find_by_order((tree.size()+1)/2 - 1) -> first);

	}
	cout<<maxmed;

}