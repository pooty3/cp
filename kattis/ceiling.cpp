#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

class node{
public:
	int val;
	node* left;
	node* right;	
	node(int v) {
		val = v;
		left = nullptr;
		right = nullptr;
	}
};

int main()
{
	int n,k;
	vvi aarr;
	cin>>n>>k;
	REP(z, n) {
		int x;
		cin>>x;
		vi arr;
		arr.push_back(1);
		node* root = new node(x);
		REPL(i, 1,k ) {
			int y;
			cin>>y;
			node* cur = root;
			int v=1;
			while (true) {
				if (y < cur->val) {
					v *= 2;
					if (cur->left == nullptr) {
						node* n = new node(y);
						cur->left = n;
						arr.push_back(v);
						break;
					} else {
						cur = cur->left;
					}
				} else {
					v = v* 2+1;
					if (cur->right == nullptr) {
						node* n = new node(y);
						cur->right = n;
						arr.push_back(v);
						break;
					} else {
						cur = cur->right;
					}
				}
			}

		}
		sort(arr.begin(), arr.end());
		bool yes = true;
		REP(i, aarr.size()) {
			if (aarr[i].size() == arr.size()) {
				bool sme = true;
				REP(j, arr.size()) {
					if (arr[j] != aarr[i][j]) {
						sme = false;
						break;
					}
				}
				if (sme) {
					yes = false;
					break;
				}
			}
		}
		if (yes) {
			aarr.push_back(arr);
		}

	}
	cout<<aarr.size();

}