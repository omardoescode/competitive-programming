/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: O - Matching
 * Contest: Educational DP Contest
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/dp/tasks/dp_o
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Sat 22 Mar 2025 01:03:18 PM EET
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

const int N = 22;
const int MOD = 1e9 + 7;
int n;
vvi coms;
int dp[1 << N][N];
int solve(int mask, int w) {
  if (w == n) // all women have been paired
    return mask == (1 << n) - 1;
  int &res = dp[mask][w];
  if (~res)
    return res;
  res = 0;
  for (int x = 0; x < n; x++) {
    if (!((mask >> x) & 1) // man not taken
        && coms[x][w])     // compatible
    {
      (res += solve(mask | (1 << x), w + 1)) %= MOD;
    }
  }
  return res;
}

void solve() {
  cin >> n;
  memset(dp, -1, sizeof(dp));
  coms.resize(n, vector<int>(n));
  for (auto &row : coms)
    for (auto &v : row)
      cin >> v;

  cout << solve(0, 0) << endl;
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
