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
ll mod = 1e9 + 7;
set<int> prime;
void setup() {
  bool primes[300001];
  memset(primes, 1, sizeof(primes));
  primes[0] = 0;
  primes[1] = 0;
  REPL(i, 2, 300001) {
    if (primes[i] == 0) continue;
    int s= i*2;
    while (s< 300001) {
      primes[s] = false;
      s +=i;
    }
    prime.insert(i);
  }

}

vvi mem(300000, vi(30, -1));
ll findmulti(int v, int c) {
  if (c == 0) {
    return 1;
  }
  if (mem[v][c] == -1) {
    mem[v][c] = (v * findmulti(v,c-1))%mod;
  }
  return mem[v][c];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  setup();
  int n,q;
  cin>>n>>q;
  unordered_map<int, multiset<int>> mp;
  vector<unordered_map<int,int>> mapping;
  vector<unordered_map<int,int>> allindmap(200001);
  REPL(i,1, 200001) {
    allindmap[i] = unordered_map<int,int>();
    if (i==1) continue;
    if (prime.find(i)!=prime.end()) {
      allindmap[i][i]++;
    } else {
      for (auto v: prime) {
        if (i%v ==0) {
          allindmap[i] = allindmap[i/v];
          allindmap[i][v]++;
          break;
        }
      }
    }
  }
  ll curgcd = 1;
  REP(i, n) {
    int x;
    cin>>x;
    mapping.push_back(allindmap[x]);
    for (auto &[v, c]: mapping[i]) {
      if (mp.find(v)==mp.end()) {
        mp.insert({v, multiset<int>()});
      }
      mp[v].insert(c);
    }
  }

  for (auto &[v, se]: mp) {
    if (se.size()!= n) {
      continue;
    }
    curgcd *= findmulti(v,*se.begin());
    curgcd %= mod;
  }
  REP(i, q) {
    int ind;
    int x;
    cin>>ind>>x;ind--;
    for (auto &[v,c]: allindmap[x]) {
      int before = mapping[ind][v];
      mapping[ind][v] += c;
      int diff = 0;
      if (before == 0) {
        mp[v].insert(c);
        if (mp[v].size() == n) {
          diff = *(mp[v].begin());
        }
      } else {
        int b = *(mp[v].begin());
        mp[v].erase(mp[v].find(before));
        mp[v].insert(before +c);
        if (mp[v].size()==n) {
          diff = *(mp[v].begin()) - b;
        }
      }

      curgcd *= findmulti(v,diff);
      curgcd %= mod;
    }
    cout<<curgcd<<"\n";
  }
}