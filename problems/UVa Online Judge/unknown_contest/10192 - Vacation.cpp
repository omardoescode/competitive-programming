/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: 10192 - Vacation
 * Contest: unknown_contest
 * Judge: UVa Online Judge
 * URL:
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1133
 * Memory Limit: 32
 * Time Limit: 3000
 * Start: Sat 15 Mar 2025 10:53:56 AM EET
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

string s0, s1;
int dp[100][100];
int solve(int i, int j) {
  if (i >= s0.size() || j >= s1.size())
    return 0;
  int &ret = dp[i][j];
  if (~ret)
    return ret;
  if (s0[i] == s1[j])
    ret = 1 + solve(i + 1, j + 1);
  else
    ret = max(solve(i, j + 1), solve(i + 1, j));
  return ret;
}
signed main() {
  FASTIO;
  int c = 0;
  while (getline(cin, s0), s0 != "#") {
    getline(cin, s1);
    memset(dp, -1, sizeof(dp));
    cout << "Case #" << ++c << ": you can visit at most ";
    cout << solve(0, 0);
    cout << " cities." << endl;
  }
}
