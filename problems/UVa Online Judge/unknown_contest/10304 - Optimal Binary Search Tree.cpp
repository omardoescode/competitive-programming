/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: 10304 - Optimal Binary Search Tree
 * Contest: unknown_contest
 * Judge: UVa Online Judge
 * URL:
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1245
 * Memory Limit: 32
 * Time Limit: 10000
 * Start: Thu 13 Mar 2025 09:32:24 AM EET
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

const int N = 255;
int pre[N], arr[N], memo[N][N], vis[N][N];
int vid, n;

int solve(int s, int e) {
  if (s >= e)
    return 0;

  int &ret = memo[s][e];
  if (vis[s][e] == vid)
    return ret;
  ret = 1e9;
  for (int p = s; p <= e; p++) {
    int c1 = solve(s, p - 1) + pre[p - 1] - pre[s - 1];
    int c2 = solve(p + 1, e) + pre[e] - pre[p];
    ret = min(ret, c1 + c2);
  }
  return ret;
}

signed main() {
  while (++vid, ~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", pre + i);
      pre[i] += pre[i - 1];
    }
    printf("%d", solve(1, n));
  }
}
