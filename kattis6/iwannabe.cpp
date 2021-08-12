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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	map<ll,int> att,def,hp;
	REP(i,n){
		ll a,d,h;
		cin>>a>>d>>h;
		att[-a] = i;
		def[-d] = i;
		hp[-h] = i;
	}
	set<int> s;
	REP(i, k) {
		s.insert(att.begin()->second);
		s.insert(def.begin()->second);
		s.insert(hp.begin()->second);
		att.erase(att.begin());
		def.erase(def.begin());
		hp.erase(hp.begin());
	}
	cout<<s.size();
}