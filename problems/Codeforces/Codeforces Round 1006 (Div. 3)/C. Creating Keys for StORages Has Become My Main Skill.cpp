/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: C. Creating Keys for StORages Has Become My Main Skill
 * Contest: Codeforces Round 1006 (Div. 3)
 * Judge: Codeforces
 * URL: https://codeforces.com/contest/2072/problem/C
 * Memory Limit: 256
 * Time Limit: 2000
 * Start: Tue 25 Feb 2025 05:08:52 PM EET
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

unsigned countBits(unsigned int number) { return (int)log2(number) + 1; }
int highestPowerof2(int n) {
  int res = 0;
  for (int i = n; i >= 1; i--) {
    if ((i & (i - 1)) == 0) {
      res = i;
      break;
    }
  }
  return res;
}
void precompute() {}

ll unset_kth_bit(ll x, int k) { return x & ~(1 << k); }
void solve() {
  in2(n, x);
  vi ans(n, 0);
  if (n == 1)
    ans[0] = x;
  else {
    int temp = x;
    int oring = 0;
    int i = 0;
    while ((temp & i) == temp)
      ans[i] = i++;
    if (oring != x)
      ans[i] = x;
  }
  cout(ans);
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
