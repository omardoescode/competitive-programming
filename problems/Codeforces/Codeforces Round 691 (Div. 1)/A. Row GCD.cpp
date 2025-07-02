/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: A. Row GCD
 * Contest: Codeforces Round 691 (Div. 1)
 * Judge: Codeforces
 * URL: https://codeforces.com/problemset/problem/1458/a
 * Memory Limit: 512
 * Time Limit: 2000
 * Start: Wed 02 Jul 2025 06:05:40 PM EEST
 */
#include "bits/stdc++.h"
#include <cstdio>
#include <numeric>

using namespace std;

#define ll long long
#define int ll
#define str string
#define endl "\n"
#define ooi (INT_MAX / 2)
#define ooll (LONG_LONG_MAX / 2)
#define ull unsigned ll
#define pdi pair<double, int>
#define pii pair<int, int>
#define pdd pair<double, double>
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

#define vec vector
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vll vector<ll>
#define all(v) begin(v), end(v)

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  in2(n, m);
  vec<int> as(n), bs(m);
  cin(as);
  cin(bs);
  int g = 0;
  for (int i = 1; i < n; i++)
    g = __gcd(g, abs(as[i] - as[0]));
  for (int v : bs)
    cout << __gcd(g, as[0] + v) << " ";
}
