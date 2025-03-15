/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Easy Longest Increasing Subsequence
 * Contest: Tutorial
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/ELIS/
 * Memory Limit: 1536
 * Time Limit: 1948
 * Start: Sun 09 Mar 2025 12:48:02 PM EET
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
const int N = 20, M = 40;
int n;
vector<int> arr;

int dp[N][M];
int sol(int i, int largest) {
  if (i == n)
    return 0;

  int &res = dp[i][largest];
  if (~res)
    return res;

  // if not taken
  int val = sol(i + 1, largest);

  // if taken
  if (arr[i] > largest)
    val = max(val, 1 + sol(i + 1, arr[i]));
  return res = val;
}

void solve() {
  cin >> n;
  memset(dp, -1, sizeof(int) * n * M);
  arr.resize(n);
  cin(arr);
  cout << sol(0, 0) << endl;
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
