/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Two Sets II
 * Contest: CSES Problem Set
 * Judge: CSES
 * URL: https://cses.fi/problemset/task/1093
 * Memory Limit: 512
 * Time Limit: 1000
 * Start: Thu 20 Mar 2025 11:43:11 PM EET
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

void precompute() {}
const int MOD = 1e9 + 7;
void solve() {
  in(n);
  int sum = n * (n + 1) / 2;
  if (sum & 1) {
    cout << 0;
    return;
  }
  sum /= 2;

  // dp[i][j]: from elements 0 to i, how many times can we get the sum `j`?
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

  dp[0][0] = 1;
  for1(i, n) for0(j, sum + 1) {
    // leave
    dp[i][j] = dp[i - 1][j];

    // take
    int prev = j - i; // to get `j` by including the current element
    if (prev >= 0)
      dp[i][j] += dp[i - 1][prev];

    dp[i][j] %= MOD;
  }

  // cout << dp[n][sum] / 2 << endl; // still true
  cout << dp[n - 1][sum] << endl; // here we don't include the nth element to
                                  // make it always in the second set
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
