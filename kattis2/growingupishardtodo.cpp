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
typedef complex<double> Complex;
int md = 1e9+7;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n;
int arr[300005], a[300005];
vector<vector<pair<int,int>>> ss;
void solve(){
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ss.resize(n+1);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        ss[i].push_back({INT_MIN, 0});
    }
    for (int i = 0;i < n; ++i) {
        int pos = lower_bound(a,a+k,arr[i])-a;
        bool rep=0;
        if (pos == k) k++;
        else rep = a[pos] == arr[i];
        a[pos] = arr[i];
        ll cur_max = rep ? ss[pos][ss[pos].size()-2].second : ss[pos].back().second;
        ll incre_val;
        if (pos == 0) incre_val = 1;
        else {
            ii p = {-arr[i],0};
            auto it = prev(upper_bound(ss[pos-1].begin(), ss[pos-1].end(), p,
                [](const pair<int,ll> p1, const pair<int,ll> p2) { return p1.first < p2.first; }));
            ll num = it->second;
            incre_val = (ss[pos-1].back().second - num + md)%md;
        }
        ll assign = (cur_max + incre_val+md)%md;
        if (rep) ss[pos].back().second = assign;
        else ss[pos].push_back({-arr[i],assign});
    }

    ll res = ss[k-1].back().second;
    cout << res << endl;
}

int main() {
    fast();
    cin >> n;
    solve();
}
