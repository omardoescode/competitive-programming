/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: B. T-primes
 * Contest: Codeforces Round 142 (Div. 2)
 * Judge: Codeforces
 * URL: https://codeforces.com/problemset/problem/230/B
 * Memory Limit: 256
 * Time Limit: 2000
 * Start: Wed 02 Jul 2025 06:21:15 PM EEST
 */
#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define str string
#define int ll
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

const int MAX = 1e7 + 10;
bitset<MAX> seive;

signed main() {
  seive.set();
  seive[0] = seive[1] = false;
  for (int i = 2; i * i < MAX; i++) {
    if (seive[i]) {
      for (int j = i * i; j < MAX; j += i) {
        seive[j] = 0;
      }
    }
  }

  cin.tie(0)->sync_with_stdio(0);
  in(t);
  while (t--) {
    in(v);
    int sq = std::sqrt(v);
    bool tprime = sq * sq == v && v > 1 && seive[sq];
    cout << (tprime ? "YES" : "NO") << endl;
  }
}
