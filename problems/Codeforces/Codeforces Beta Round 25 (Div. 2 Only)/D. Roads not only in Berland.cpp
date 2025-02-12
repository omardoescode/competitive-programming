/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 */
#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define str string
#define ooi (INT_MAX / 2)
#define ooll (LONG_LONG_MAX / 2)
#define ull unsigned ll
#define pdi pair<double, int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define int long long
#define in(a)                                                                  \
  int a;                                                                       \
  cin >> a;
#define in2(a, b)                                                              \
  int a, b;                                                                    \
  cin >> a >> b;
#define in3(a, b, c)                                                           \
  int a, b, c;                                                                 \
  cin >> a >> b >> c;
#define cin(a)                                                                 \
  for (auto &v : a)                                                            \
  cin >> v
#define cout(a)                                                                \
  for (auto &v : a)                                                            \
    cout << v << " ";                                                          \
  cout << endl
#define FASTIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define vec vector
#define veci vector<int>
#define vecll vector<ll>
#define all(v) v.begin(), v.end()

class DSU {
public:
  DSU(size_t size) : count(size), _par(size), _rank(size) {
    for (int i = 0; i < size; i++) {
      _par[i] = i;
      _rank[i] = 0;
    }
  }

  void reInit(size_t size) {
    _par.resize(size);
    _rank.resize(size);
    count = 0;
  }

  /**
  * Without Path Compression
   int find_set(int v) {
    if (v == _par[v])
      return v;
    return find_set(_par[v]);
  }
  */
  int find_set(int v) {
    if (v == _par[v])
      return v;
    return _par[v] = find_set(_par[v]);
  }

  // return true if they weren't unioned
  bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
      if (_rank[a] < _rank[b])
        swap(a, b);
      _par[b] = a;
      if (_rank[a] == _rank[b])
        _rank[a]++;
      count--;
      // assert(count >= 0); // just to help in debugging
      return true;
    }
    return false;
  }

  int get_count() const { return count; }

private:
  vector<int> _par, _rank;
  int count;
};

void precompute() {}

void solve() {
  in(n);
  DSU d(n);
  vec<pii> uneeded;
  for (int i = 0; i < n - 1; i++) {
    in2(a, b);
    a--, b--;
    if (!d.union_sets(a, b)) {
      uneeded.emplace_back(a, b);
    }
  }

  cout << d.get_count() - 1 << endl;
  int cnt = d.get_count();
  int k = 0;

  for (int i = 0; i < n && cnt != 1; i++) {
    for (int j = i + 1; j < n && cnt != 1; j++) {
      if (d.find_set(i) != d.find_set(j)) {
        d.union_sets(i, j);
        cout << uneeded[k].first + 1 << " " << uneeded[k].second + 1 << " "
             << i + 1 << " " << j + 1 << endl;
        cnt--, k++;
      }
    }
  }
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  int t = 1, c = 0;
  // cin >> t;
  precompute();
  while (t--)
    solve();
}
