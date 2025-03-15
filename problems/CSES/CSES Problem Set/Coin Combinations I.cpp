/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Coin Combinations I
 * Contest: CSES Problem Set
 * Judge: CSES
 * URL: https://cses.fi/problemset/task/1635
 * Memory Limit: 512
 * Time Limit: 1000
 * Start: Sat 15 Mar 2025 06:57:08 PM EET
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

const int MAX_X = 1e6 + 15;
const int MOD = 1e9 + 7;
int dp[MAX_X], cnt, x;
int arr[115];
bool vis[MAX_X];

void solve() {
  memset(dp, 0, sizeof(dp));
  memset(vis, 0, sizeof(vis));
  cin >> cnt >> x;
  for0(i, cnt) cin >> arr[i];

  dp[0] = 1;
  vis[0] = true;
  for0(i, x + 1) {
    if (vis[i]) {
      for0(j, cnt) {
        if (i + arr[j] <= x) {
          dp[i + arr[j]] += dp[i];
          dp[i + arr[j]] %= MOD;
          vis[i + arr[j]] = true;
        }
      }
    }
  }
  cout << dp[x] << endl;
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
