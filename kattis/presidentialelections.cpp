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
vll votes;
vi deles;
vvll arr;
ll findmin(int needed, int cur) {
	if (needed<=0) {return 0;}
	if (cur < 0) {return INF;}
	if (arr[needed][cur] == -1) {
		ll havemin = findmin(needed - deles[cur], cur-1) + votes[cur];
		ll nhavemin = findmin(needed, cur-1);
		arr[needed][cur] = min(havemin, nhavemin);
	}
	return arr[needed][cur];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int s;
	cin>>s;
	int tot=0;
	int forsure=0;
	REP(i, s) {
		int d,c,f,u;
		cin>>d>>c>>f>>u;
		tot +=d;
		ll req = (c+f+u)/2 +1 - c;
		if (req<= 0) {
			forsure+=d;
		} else if (req>u){

		} else {
			votes.push_back(req);
			deles.push_back(d);
		}
	}
	int needed = tot/2 +1 - forsure;
	if (votes.size()>0) {
		arr.assign(needed+1, vll(votes.size(), -1));
	}

	ll amt = findmin(needed, votes.size()-1);
	if (amt >= INF) {
		cout<<"impossible";
	} else {
		cout<<amt;
	}


}