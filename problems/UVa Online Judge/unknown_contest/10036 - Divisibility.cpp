/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: 10036 - Divisibility
 * Contest: unknown_contest
 * Judge: UVa Online Judge
 * URL:
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=977
 * Memory Limit: 32
 * Time Limit: 3000
 * Start: Sat 15 Mar 2025 09:48:58 AM EET
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

void precodpute() {}

const int N = 10015, M = 110;
int n, K;
v<int> arr;
int dp[N][N];
bool solve(int i, int k) {
  int &ret = dp[i][k];
  if (~ret)
    return ret;
  if (i == n)
    return ret = (k % K == 0);
  return ret = solve(i + 1, (k - arr[i]) % K) || solve(i + 1, (k + arr[i]) % K);
}
void solve() {
  cin >> n >> K;
  memset(dp, -1, sizeof(dp));
  arr.resize(n);
  cin(arr);

  cout << (solve(1, K - arr[0]) ? "Divisible" : "Not divisible") << endl;
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  int t = 1, c = 0;
  cin >> t;
  precodpute();
  while (t--)
    solve();
}
