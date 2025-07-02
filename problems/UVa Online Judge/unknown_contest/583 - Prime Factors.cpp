/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: 583 - Prime Factors
 * Contest: unknown_contest
 * Judge: UVa Online Judge
 * URL:
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524
 * Memory Limit: 32
 * Time Limit: 3000
 * Start: Wed 02 Jul 2025 06:48:39 PM EEST
 */
#include "bits/stdc++.h"

using namespace std;

#define ll long long
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

const int MAX = 46340;
bitset<MAX> seive;
signed main() {
  seive.set();
  seive[0] = seive[1] = 0;

  vec<ll> primes;
  for (ll i = 2; i * i < MAX; i++)
    if (seive[i]) {
      for (ll j = i * i; j < MAX; j += i)
        seive[j] = 0;
    }
  for (int i = 2; i < MAX; i++)
    if (seive[i])
      primes.push_back(i);

  cin.tie(0)->sync_with_stdio(0);
  ll n;
  while (scanf("%lld", &n), n != 0) {
    printf("%lld = ", n);

    if (n < 0)
      printf("-1 x "), n *= -1;

    bool print_x = false;
    for (int pos = 0; primes[pos] * primes[pos] <= n && pos < primes.size();
         pos++) {
      int p = primes[pos];
      while (n % p == 0) {
        if (print_x)
          printf(" x ");
        else
          print_x = true;

        printf("%lld", p), n /= p;
      }
    }
    if (n > 1) {
      if (print_x)
        printf(" x ");
      else
        print_x = true;
      printf("%lld", n);
    }

    puts("");
  }
}
