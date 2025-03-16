/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Where is the Ghost
 * Contest: unknown_contest
 * Judge: Toph
 * URL: https://toph.co/p/where-is-the-ghost
 * Memory Limit: 256
 * Time Limit: 1000
 * Start: Sun 16 Mar 2025 12:47:14 PM EET
 */
// Tutorial: https://www.youtube.com/watch?v=rUDdZrEX_pQ
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

const int N = 1e4 + 15, LCM = 2520, MOD = 1e9 + 7;

int dp[N][LCM], n, arr[N];
// starting from index `i`, get the number of subsets that give us a remainder
// of `rem` at each step,
// we have two options
// 1. Leave the current element, thus have the same remainder
// 2. Take the current element, thus we have (product so far * arr[i]) % LCM = p
// * LCM * arr[i] % LCM = rem * arr[i] % LCM
int go(int i, int rem) {
  if (i == n)
    return (rem == 0);
  int &ret = dp[i][rem];
  if (~ret)
    return ret;
  return ret = (go(i + 1, rem) % MOD +                 /* leave */
                go(i + 1, (rem * arr[i]) % LCM) % MOD) /* take */
               % MOD;
}

// 2520 = 2^3 * 3 ^ 2 * 5 * 7
int dp2[N][4][3][2][2];
int go2(int i, int c2, int c3, int c5, int c7) {
  if (i == n)
    return c2 == 3 && c3 == 2 && c5 == 1 && c7 == 1;

  int &ret = dp2[i][c2][c3][c5][c7];
  if (~ret)
    return ret;
  ret = go2(i + 1, c2, c3, c5, c7) % MOD; // leave

  int x = arr[i];
  int cnt[8] = {0};
  for (int j : {2, 3, 5, 7}) {
    while (x % j == 0)
      cnt[j]++, x /= j;
  }
  ret += go2(i + 1, min(3, c2 + cnt[2]), min(2, c3 + cnt[3]),
             min(1, c5 + cnt[5]), min(1, c7 + cnt[7]));
  ret %= MOD;
  return ret;
}
void solve() {
  cin >> n;
  for0(i, n) cin >> arr[i];
  memset(dp2, -1, sizeof(dp2));
  // cout << go(0, 1); // 1 here stands for 1 % lCM = 1
  cout << go2(0, 0, 0, 0, 0); // 1 here stands for 1 % lCM = 1
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
