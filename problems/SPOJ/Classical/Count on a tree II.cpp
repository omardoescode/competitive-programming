/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Count on a tree II
 * Contest: Classical
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/COT2/
 * Memory Limit: 1536
 * Time Limit: 1207
 * Start: Fri 21 Feb 2025 03:57:44 PM EET
 */
#include "bits/stdc++.h"
#include <iterator>
#include <utility>

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

const int N = 1e5 + 10, M = 17;
struct Query {
  int s, e, lca, i;
};

int nti[N], itn[N], dpth[N], cnt, start[N], ed[N], dfs_order[N], tim, freq[N],
    distinct;
v<v<int>> adj;
int st[M][N];
int Log[N];
vi weights, ans;
v<Query> queries;
bool isInside[N];

void precal_log(int n) {
  Log[0] = -1; // undefined
  for (int i = 0; i < n; i++)
    Log[i + 1] = Log[i] + !(i & (i + 1));
}

void dfs(int u, int parent, int d) {
  nti[u] = cnt;
  itn[cnt] = u;
  dpth[cnt] = d;
  cnt++;

  dfs_order[tim] = u;
  start[u] = tim;
  tim++;

  for (auto &v : adj[u]) {
    if (v == parent)
      continue;
    dfs(v, u, d + 1);
    itn[cnt] = u;
    dpth[cnt] = d;
    cnt++;
  }

  dfs_order[tim] = u;
  ed[u] = tim;
  tim++;
}

void precompute() {}

void print_arr(
    string s, int arr[], int size,
    function<string(int)> func = [](int value) { return to_string(value); }) {
  cout << s << endl;
  for0(i, size) cout << func(arr[i]) << " ";
  cout << endl;
}
void build_st(int n) {
  for0(i, cnt) st[0][i] = i;

  for (int j = 1; 1 << j <= cnt; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      int a = st[j - 1][i], b = st[j - 1][i + (1 << (j - 1))];
      st[j][i] = (dpth[a] < dpth[b] ? a : b);
    }
  }
}

int rmq(int s, int e) {
  int sz = e - s + 1;
  int l = Log[sz];
  int a = st[l][s], b = st[l][e - (1 << l) + 1];
  return dpth[a] < dpth[b] ? a : b;
}

int lca(int u, int v) {
  u = nti[u], v = nti[v];
  if (u > v)
    swap(u, v);
  return itn[rmq(u, v)];
}

void toggle(int x) {
  if (isInside[x]) {
    // erase
    freq[weights[x]]--;
    if (freq[weights[x]] == 0) {
      distinct--;
    }
    isInside[x] = false;
  } else {
    freq[weights[x]]++;
    if (freq[weights[x]] == 1) {
      distinct++;
    }
    isInside[x] = true;
  }
}
int gs = 0, ge = 0;
void answer(Query &q) {
  auto &[s, e, lc, i] = q;
  while (gs > s) {
    gs--;
    toggle(dfs_order[gs]);
  }
  while (ge < e + 1) {
    toggle(dfs_order[ge]);
    ge++;
  }
  while (gs < s) {
    toggle(dfs_order[gs]);
    gs++;
  }
  while (ge > e + 1) {
    ge--;
    toggle(dfs_order[ge]);
  }

  toggle(lc);
  ans[i] = distinct;
  toggle(lc);
}
void solve() {
  in2(n, q);
  unordered_map<int, int> compress;
  weights.resize(n);
  queries.resize(q);
  ans.resize(q);

  for0(i, n) {
    in(val);
    val =
        compress.count(val) ? compress[val] : (compress[val] = compress.size());
    weights[i] = val;
  }

  adj.resize(n);
  for1(i, n - 1) {
    in2(a, b);
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1, 0);

  // print_arr("nti", nti, n);
  // print_arr("dpth", dpth, cnt);
  // print_arr("itn", itn, cnt);
  // print_arr("def_order", dfs_order, tim);
  // print_arr("start", start, n);
  // print_arr("end", ed, n);

  precal_log(cnt);
  build_st(cnt);

  for0(i, q) {
    in2(u, w);
    u--, w--;
    if (start[u] > start[w])
      swap(u, w);
    int lc = lca(u, w);
    queries[i] = {u == lc ? start[u] + 1 : ed[u], start[w], lc, i};
  }
  const int sq = sqrt(n);
  sort(all(queries), [sq](const Query &a, const Query &b) {
    return make_pair(a.s / sq, a.e) < make_pair(b.s / sq, b.e);
  });
  for (auto &q : queries)
    answer(q);

  for0(i, q) cout << (ans[i]) << endl;
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
