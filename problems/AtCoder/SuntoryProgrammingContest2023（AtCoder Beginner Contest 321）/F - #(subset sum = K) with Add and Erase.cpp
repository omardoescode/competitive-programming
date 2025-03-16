// Studying this editorial: https://atcoder.jp/contests/abc321/tasks/abc321_f
/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: F - #(subset sum = K) with Add and Erase
 * Contest: SuntoryProgrammingContest2023（AtCoder Beginner Contest 321）
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/abc321/tasks/abc321_f
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Sat 15 Mar 2025 09:24:35 PM EET
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

#define MOD 998244353
const int N = 5015;
int dp[N];
void solve() {
  in2(q, k);
  dp[0] = 1;
  while (q--) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '+') {
      for (int i = k; i >= x; i--) {
        dp[i] += dp[i - x];
        dp[i] %= MOD;
      }
    } else {
      for (int i = x; i <= k; i++) {
        dp[i] += (MOD - dp[i - x]);
        dp[i] %= MOD;
      }
    }
    cout << dp[k] << endl;
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
