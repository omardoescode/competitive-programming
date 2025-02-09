/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 */
#include "bits/stdc++.h"
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

#define ll long long
#define str string
#define oo (int)20000000
#define ull unsigned ll
#define pdi pair<double, int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define endl "\n"
#define in(a)                                                                  \
  int a;                                                                       \
  cin >> a
#define in2(a, b)                                                              \
  int a, b;                                                                    \
  cin >> a >> b
#define in3(a, b, c)                                                           \
  int a, b, c;                                                                 \
  cin >> a >> b >> c

#define vec vector
#define veci vector<int>
#define vecll vector<ll>
#define all(v) v.begin(), v.end()
#define FASTIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

class DSU {
public:
  DSU(size_t size) : count(0), _par(size) {}

  void reInit(size_t size) {
    _par.resize(size);
    count = 0;
  }

  void make_set(int v) {
    _par[v] = v;
    count++;
  }

  int find_set(int v) {
    if (v == _par[v])
      return v;
    return _par[v] = find_set(_par[v]);
  }
  // int find_set(int v) {
  //   if (v == _par[v])
  //     return v;
  //   return _par[v] = find_set(_par[v]);
  // }

  // returns true is they weren't unioned already and have been now
  // false if were unixned
  bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
      _par[b] = a;
      count--;
      assert(count >= 0); // just to help in debugging
      return true;
    }
    return false;
  }

  // Expose this to public
  vector<int> _par;
  int count;
};

void solve() {
  in2(n, m);
  DSU d(n);
  vector<pair<int, int>> queries;
  vector<bool> done(m, true);

  for (int i = 0; i < n; i++) {
    d.make_set(i);
  }
  for (int i = 0; i < m; i++) {
    in2(a, b);
    a--, b--;
    queries.emplace_back(a, b);
  }

  in(q);
  stack<int> to_do;
  stack<int> counts;
  while (q--) {
    in(a);
    a--;
    done[a] = false;
    to_do.push(a);
  }

  for (int i = 0; i < m; i++) {
    if (done[i])
      d.union_sets(queries[i].first, queries[i].second);
  }

  while (!to_do.empty()) {
    int a = to_do.top();
    to_do.pop();
    counts.push(d.count);
    d.union_sets(queries[a].first, queries[a].second);
  }

  while (!counts.empty()) {
    cout << counts.top() << " ";
    counts.pop();
  }
}

signed main() {
  int t = 1, c = 0;
  // scanf("%d", &t);
  while (t--)
    solve();
}
