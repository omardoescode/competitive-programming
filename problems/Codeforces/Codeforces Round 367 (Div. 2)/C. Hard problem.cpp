/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: C. Hard problem
 * Contest: Codeforces Round 367 (Div. 2)
 * Judge: Codeforces
 * URL: https://codeforces.com/problemset/problem/706/C
 * Memory Limit: 256
 * Time Limit: 1000
 * Start: Thu 20 Mar 2025 10:13:37 PM EET
 */
#include "bits/stdc++.h"
#include <algorithm>

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
#define int ll
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()

#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define __lcm(a, b) ((a * b) / (__gcd(a, b)))
#define unq(v) (v).erase(unique(all((v)), (v).end()))
#define oo 1000000000000000

const int N = 1e5 + 10;
void solve() {
  int n;
  vector<int> vals;
  vector<string> strs, reversed_strs;
  int dp[N][2];
  cin >> n;
  vals.resize(n);
  strs.resize(n);
  reversed_strs.resize(n);
  cin(vals);
  for0(i, n) {
    cin >> strs[i];
    reversed_strs[i] = strs[i];
    std::reverse(all(reversed_strs[i]));
    dp[i][0] = dp[i][1] = oo;
  }

  dp[0][0] = 0;
  dp[0][1] = vals[0];
  for (int i = 1; i < n; i++) {
    if (strs[i] >= strs[i - 1])
      dp[i][0] = dp[i - 1][0];
    if (strs[i] >= reversed_strs[i - 1])
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);

    // try to reverse
    if (reversed_strs[i] >= strs[i - 1])
      dp[i][1] = dp[i - 1][0] + vals[i];
    if (reversed_strs[i] >= reversed_strs[i - 1])
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + vals[i]);
  }

  int res = min(dp[n - 1][0], dp[n - 1][1]);
  if (res == oo)
    cout << -1;
  else
    cout << res;
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  int t = 1, c = 0;
  // cin >> t;
  while (t--)
    solve();
}
