/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Lowest Common Ancestor
 * Contest: unknown_contest
 * Judge: Library Checker
 * URL: https://judge.yosupo.jp/problem/lca
 * Memory Limit: 1024
 * Time Limit: 5000
 * Start: Fri 21 Feb 2025 08:33:09 AM EET
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

const int N = 1e6 + 10, M = 20;

int nti[N], itn[N], dpth[N], cnt;
v<v<int>> adj;
int st[M][N];
int Log[N];

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

  for (auto &v : adj[u]) {
    if (v == parent)
      continue;
    dfs(v, u, d + 1);
    itn[cnt] = u;
    dpth[cnt] = d;
    cnt++;
  }
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

void solve() {
  in2(n, q);
  adj.resize(n);
  for1(i, n - 1) {
    in(par);
    adj[i].push_back(par);
    adj[par].push_back(i);
  }

  dfs(0, -1, 0);

  // print_arr("nti", nti, n);
  // print_arr("dpth", dpth, cnt);
  // print_arr("itn", itn, cnt);

  precal_log(cnt);
  build_st(cnt);

  for0(i, q) {
    in2(u, v);
    cout << lca(u, v) << endl;
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
