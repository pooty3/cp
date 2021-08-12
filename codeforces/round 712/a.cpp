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

void solve() {
	int n;
	cin>>n;
	string str;
	cin>>str;
	vector<char> arr1(n),arr2(n);
	int co =0;
	REP(i, n) {
		if (str[i]=='1')co++;
	}
	if (co%2 !=0) {
		cout<<"NO\n";
		return;
	}
	bool yes = true;
	co /=2;
	REP(i, n) {
		if (str[i]=='1') {
			if (co > 0) {
				arr1[i]='(';arr2[i]='(';
			} else {
				arr1[i] =')';arr2[i]=')';
			}
			co--;
		} else {
			arr1[i] = yes ? '(':')';
			arr2[i] = yes?')':'(';
			yes = !yes;
		}
	}
	int v1=0,v2=0;
	REP(i, n) {
		v1 += arr1[i] == '(' ?1:-1;
		v2 += arr2[i] =='('?1:-1;
		if (v1<0||v2<0) {
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	REP(i, n) {
		cout<<arr1[i];
	}
	cout<<"\n";
	REP(i, n) {
		cout<<arr2[i];
	}
	cout<<"\n";

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