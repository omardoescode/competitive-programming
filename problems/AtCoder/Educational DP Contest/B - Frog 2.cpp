/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: B - Frog 2
 * Contest: Educational DP Contest
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/dp/tasks/dp_b
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Sun 09 Mar 2025 12:34:52 PM EET
 */
#include "bits/stdc++.h"
#include <climits>

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
#define int ll

const int N = 10e5 + 10;
int n, k;
int heights[N];

int dp[N];
int min_value(int i) {
  // if solved before
  if (i == n - 1)
    return 0;
  int &ret = dp[i];
  if (~ret)
    return ret;

  ret = LLONG_MAX;
  for1(l, k) {
    if (i + l > n - 1)
      break;
    ret = min(ret, abs(heights[i] - heights[i + l]) + min_value(i + l));
  }

  return ret;
}
void solve() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  for0(i, n) cin >> heights[i];
  cout << min_value(0) << endl;
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
