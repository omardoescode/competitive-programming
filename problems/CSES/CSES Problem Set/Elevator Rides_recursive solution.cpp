/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Elevator Rides
 * Contest: CSES Problem Set
 * Judge: CSES
 * URL: https://cses.fi/problemset/task/1653
 * Memory Limit: 512
 * Time Limit: 1000
 * Start: Sat 22 Mar 2025 01:42:40 PM EET
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

const int N = 21;
int n, x;
pair<int, int> dp[1 << N];
int vis[1 << N];
vi weights;
pair<int, int> best(int s) {
  if (s == 0)      // no people
    return {1, 0}; // at least one ride for no people
  auto &ret = dp[s];
  if (vis[s])
    return ret;

  vis[s] = 1;

  ret = {n + 1, 0}; // initial value
  // try the next optimal person
  for (int p = 0; p < n; p++) {
    if (s & (1 << p)) // This person exists, let's try removing them
    {
      auto option = best(s ^ (1 << p));
      if (option.second + weights[p] <= x)
        option.second += weights[p];
      else
        option.first++, option.second = weights[p];
      ret = min(ret, option);
    }
  }
  return ret;
}
void solve() {
  cin >> n >> x;
  weights.resize(n);
  cin(weights);
  cout << best((1 << n) - 1).first << endl;
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
