/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: D - Div Game
 * Contest: AtCoder Beginner Contest 169
 * Judge: AtCoder
 * URL: https://atcoder.jp/contests/abc169/tasks/abc169_d
 * Memory Limit: 1024
 * Time Limit: 2000
 * Start: Tue 01 Jul 2025 06:40:48 PM EEST
 */
#include "bits/stdc++.h"

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

int count_prime_divs(int num) {
  int res = 0;
  for (ll i = 2; i * i <= num; i++) {
    int total_count = 0;
    int next_count = 1;
    while (num % i == 0) {
      total_count++;
      if (total_count == next_count)
        res += 1, total_count = 0, next_count++;
      num /= i;
    }
  }

  if (num > 1)
    res += 1;

  return res;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  in(n);
  cout << count_prime_divs(n) << endl;
}
