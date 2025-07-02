/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: C - Twin Primes
 * Contest: Sieve - divisors - factorization
 * Judge: Virtual Judge
 * URL: https://vjudge.net/contest/673569#problem/C
 * Memory Limit: 1024
 * Time Limit: 3000
 * Start: Wed 02 Jul 2025 06:36:56 PM EEST
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

const int MAX = 20000000 + 12;
bitset<MAX> seive;

signed main() {
  seive.set();
  seive[0] = seive[1] = false;
  for (int i = 2; i * i < MAX; i++)
    if (seive[i])
      for (int j = i * i; j < MAX; j += i)
        seive[j] = false;

  vec<pii> res;

  for (int i = 3; i < MAX - 2; i++)
    if (seive[i] && seive[i + 2])
      res.emplace_back(i, i + 2);

  cin.tie(0)->sync_with_stdio(0);
  int n;
  while (scanf("%d", &n) != -1) {
    n--;
    printf("(%d, %d)\n", res[n].first, res[n].second);
  }
}
