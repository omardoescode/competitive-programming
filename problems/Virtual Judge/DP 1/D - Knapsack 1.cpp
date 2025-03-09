/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: D - Knapsack 1
 * Contest: DP 1
 * Judge: Virtual Judge
 * URL: https://vjudge.net/contest/697660#problem/D
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Sun 09 Mar 2025 07:09:17 AM EET
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
#define int ll
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

const int N = 100 + 10, C = 10e5 + 10;
int n, c;
vector<int> weights(N), values(N);

// Normal recursive 2^n solution
int max_value(int idx, int capacity) {
  if (idx == n)
    return 0;

  // At item i, option 1: Take it
  int take = 0;
  if (capacity >= weights[idx])
    take = values[idx] + max_value(idx + 1, capacity - weights[idx]);

  // option 2
  int leave = max_value(idx + 1, capacity);

  return max(take, leave);
}

int dp[C][N];
int max_value_dp(int idx, int capacity) {
  if (idx == n)
    return 0;

  // Solved before
  int &ret = dp[capacity][idx];
  if (~ret)
    return dp[capacity][idx];

  // not solved before
  // At item i, option 1: Take it
  int take = 0;
  if (capacity >= weights[idx])
    take = values[idx] + max_value(idx + 1, capacity - weights[idx]);

  // option 2, leave it
  int leave = max_value(idx + 1, capacity);

  return ret = max(take, leave);
}

signed main() {
  FASTIO;
  cin >> n >> c;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> weights[i] >> values[i];
  }
  cout << max_value_dp(0, c) << endl;
}
