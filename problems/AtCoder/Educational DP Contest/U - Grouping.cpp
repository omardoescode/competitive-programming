/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: U - Grouping
 * Contest: Educational DP Contest
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/dp/tasks/dp_u
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Tue 24 Jun 2025 06:41:04 PM EEST
 */
#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define int ll
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

#define vec vector
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  in(n);
  int com[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      in(x);
      com[i][j] = x;
    }
  }

  // Generate all masks default values
  vector<int> dp(1 << n, 0);
  for (int mask = 0; mask < (1 << n); mask++)
    for (int u = 0; u < n; u++)
      if (mask & (1 << u))
        for (int v = u + 1; v < n; v++)
          if (mask & (1 << v))
            dp[mask] += com[u][v];

  // Try to maximize
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int submask = mask; submask; submask = (submask - 1) & mask) {
      int other = mask ^ submask;
      dp[mask] = max(dp[mask], dp[other] + dp[submask]);
    }
  }

  cout << dp[(1 << n) - 1] << endl;
}
