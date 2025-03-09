/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: C - Vacation
 * Contest: Educational DP Contest
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/dp/tasks/dp_c
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Sun 09 Mar 2025 08:18:00 AM EET
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

const int N = 1e5 + 10;
int n;
int as[N], bs[N], cs[N];
int dp[N][3];
int sol(int i, int cannot) {
  if (i == n)
    return 0;

  int &ret = dp[i][cannot - 'A'];
  if (~ret)
    return ret;

  // calc
  int take_a = cannot == 'A' ? 0 : as[i] + sol(i + 1, 'A');
  int take_b = cannot == 'B' ? 0 : bs[i] + sol(i + 1, 'B');
  int take_c = cannot == 'C' ? 0 : cs[i] + sol(i + 1, 'C');

  return ret = max({take_a, take_b, take_c});
}

signed main() {
  FASTIO;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> as[i] >> bs[i] >> cs[i];
  memset(dp, -1, sizeof(dp));
  cout << max({sol(0, 'A'), sol(0, 'B'), sol(0, 'C')}) << endl;
}
