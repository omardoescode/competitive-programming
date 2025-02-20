/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Matchsticks
 * Contest: MAY13
 * Judge: CodeChef
 * URL: https://www.codechef.com/problems/MSTICK
 * Memory Limit: 256
 * Time Limit: 3000
 * Start: Thu 20 Feb 2025 09:22:12 AM EET
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

const int N = 1e5 + 10;
int Log[N];
v<v<pii>> st;
void precal_log(int n) {
  Log[0] = -1;
  for (int i = 0; i < n; i++)
    Log[i + 1] = Log[i] + !(i & (i + 1));
}
void precompute() {}

void build(int lim, int n) {
  for (int j = 1; j <= lim; ++j)
    for (int i = 0; i + (1 << j) <= n + 1; i++) {
      st[j][i].first =
          min(st[j - 1][i].first, st[j - 1].size() <= (i + (1 << (j - 1)))
                                      ? INT_MAX
                                      : st[j - 1][i + (1 << (j - 1))].first);
      st[j][i].second =
          max(st[j - 1][i].second, st[j - 1].size() <= (i + (1 << (j - 1)))
                                       ? INT_MIN
                                       : st[j - 1][i + (1 << (j - 1))].second);
    }
}

int get_min(int l, int r) {
  int sz = r - l + 1;
  int lg = Log[sz];
  return min(st[lg][l].first, st[lg][r - (1 << lg) + 1].first);
}

int get_max(int l, int r) {
  int sz = r - l + 1;
  int lg = Log[sz];
  return max(st[lg][l].second, st[lg][r - (1 << lg) + 1].second);
}

void solve() {
  in(n);
  precal_log(n);
  vi arr(n);
  const int M = Log[n];
  st.resize(M + 1, vector<pair<int, int>>(n, {0, 0}));
  st[0].resize(n);
  for0(i, n) {
    in(val);
    st[0][i].first = st[0][i].second = arr[i] = val;
  }
  build(M, n);
  in(q);
  while (q--) {
    in2(l, r);
    double min_in_range = get_min(l, r);
    double max_left_range = (0 == l ? 0 : get_max(0, l - 1));
    double max_right_range = (n - 1 == r ? 0 : get_max(r + 1, n - 1));
    double max_in_range = get_max(l, r);
    cout << fixed << setprecision(1)
         << (min_in_range + max(max(max_left_range, max_right_range),
                                (max_in_range - min_in_range) / 2.0))
         << endl;
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
