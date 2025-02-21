/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Query on a tree III
 * Contest: Classical
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/PT07J/en/
 * Memory Limit: 1536
 * Time Limit: 1000
 * Start: Fri 21 Feb 2025 09:33:04 AM EET
 */
#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define str string
#define ooi (INT_MAX / 2)
#define ooll (LONG_LONG_MAX / 2)
#define ull unsigned ll
#define pdi pair<double, int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define endl "\n"
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

#define v vector
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()

#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define __lcm(a, b) ((a * b) / (__gcd(a, b)))
#define unq(v) (v).erase(unique(all((v)), (v).end()))

typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

struct Query {
  int s, e, k, i;
};

void precompute() {}

void print_arr(
    string s, vi arr,
    function<string(int)> func = [](int value) { return to_string(value); }) {
  cout << s << endl;
  for0(i, arr.size()) cout << func(arr[i]) << " ";
  cout << endl;
}

vvi adj;
vi dfs_order, st, ed, labels;
int tme = 0;
v<Query> queries;
vi ans;
ordered_set values;
void build(int u, int parent) {
  dfs_order[tme] = u;
  st[u] = tme;
  tme++;
  for (auto &v : adj[u]) {
    if (v == parent)
      continue;

    build(v, u);
  }
  ed[u] = tme - 1;
}

void add(int x) { values.insert({labels[x], x}); }
void erase(int x) { values.erase({labels[x], x}); }

int s = 0, e = 0;
void answer(int qi) {
  auto &[st, ed, k, i] = queries[qi];
  while (s > st) {
    s--;
    add(dfs_order[s]);
  }
  while (e < ed + 1) {
    add(dfs_order[e]);
    e++;
  }
  while (s < st) {
    erase(dfs_order[s]);
    s++;
  }
  while (e > ed + 1) {
    e--;
    erase(dfs_order[e]);
  }

  ans[i] = values.find_by_order(k)->second + 1;
}
void solve() {
  in(n);
  int sq = sqrt(n);
  adj.resize(n);
  dfs_order.resize(n);
  st.resize(n);
  ed.resize(n);
  labels.resize(n);
  cin(labels);
  for0(i, n - 1) {
    in2(a, b);
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  build(0, -1);
  // print_arr("dfs_order", dfs_order);
  // print_arr("st", st);
  // print_arr("ed", ed);

  in(q);
  queries.resize(q);
  ans.resize(q);
  for0(i, q) {
    in2(u, k);
    u--, k--;
    queries[i] = {st[u], ed[u], k, i};
  }
  sort(all(queries), [sq](const Query &a, const Query &b) {
    return make_pair(a.s / sq, a.e) < make_pair(b.s / sq, b.e);
  });

  for0(i, q) answer(i);
  for (auto &v : ans)
    cout << v << endl;
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
