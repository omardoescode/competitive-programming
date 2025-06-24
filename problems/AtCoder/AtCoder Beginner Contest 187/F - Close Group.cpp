/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: F - Close Group
 * Contest: AtCoder Beginner Contest 187
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/abc187/tasks/abc187_f
 * Memory Limit: 1024
 * Time Limit: 3000
 * Start: Tue 24 Jun 2025 06:10:24 PM EEST
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

signed main() {
  FASTIO;
  in2(n, m);
  vector<int> mat(n, 0);
  for (int i = 0; i < m; i++) {
    int u, b;
    cin >> u >> b;
    u--, b--;
    mat[u] |= (1 << b);
    mat[b] |= (1 << u);
  }

  // Find all complete graphs
  vector<int> dp(1 << n, INT32_MAX);

  for (int mask = 0; mask < (1 << n); mask++) {
    bool connected = true;
    for (int u = 0; u < n; u++) {
      if (((mask >> u) & 1) != 0) {
        // u is in the mask
        // Now we have to check if u is connected to all other nodes in mask
        if (((mat[u] | (1 << u)) & mask) != mask) {
          connected = false;
          break;
        }

        // mat[u] | (1 << u) is all nodes its connected to including itself
        // If we and with the mask, then we must get the mask back, otherwise,
        // it's not connected
      }
    }

    if (connected)
      dp[mask] = 1;
  }

  // Now, we have 1 where all connected components are
  // We will try to go through all submasks of all masks, and try to generate 2
  // subsets out of it: `submask` and `subset`. If both are already connected,
  // thus we can change the value by the sum of them.
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int submask = mask; submask; submask = (submask - 1) & mask) {
      int subset = mask ^ submask;

      if (dp[subset] != INT32_MAX && dp[submask] != INT32_MAX) {
        // The number of complete graphs will be the number of complete graphs
        // in both added We use min here, because they are inf (INT32_MAX) by
        // default
        dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
      }
    }
  }

  cout << dp[(1 << n) - 1] << endl;
}
