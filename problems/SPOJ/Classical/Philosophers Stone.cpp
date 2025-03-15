/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Philosophers Stone
 * Contest: Classical
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/BYTESM2/
 * Memory Limit: 1536
 * Time Limit: 1000
 * Start: Sat 15 Mar 2025 10:36:58 AM EET
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

const int N = 200;
int h, w;
int arr[N][N];
int dp[N][N];
int find_res(int i, int j) {
  int &ret = dp[i][j];
  if (~ret)
    return ret;
  if (i > h || j > w || i == 0 || j == 0)
    return ret = 0;

  return ret = arr[i][j] + max({
                               find_res(i + 1, j - 1),
                               find_res(i + 1, j),
                               find_res(i + 1, j + 1),
                           });
}
void solve() {
  cin >> h >> w;
  memset(arr, 0, sizeof(arr));
  memset(dp, -1, sizeof(dp));

  for1(i, h) for1(j, w) cin >> arr[i][j];
  int res = find_res(1, 1);
  for (int j = 2; j <= w; j++)
    res = max(res, find_res(1, j));
  cout << res << endl;
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  int t = 1, c = 0;
  cin >> t;
  precompute();
  while (t--)
    solve();
}
