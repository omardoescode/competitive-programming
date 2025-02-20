/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Catapult that ball
 * Contest: Classical
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/THRBL/
 * Memory Limit: 1536
 * Time Limit: 1000
 * Start: Wed 19 Feb 2025 06:43:39 AM EET
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
#define vvi v<v<int>>
#define vvl v<v<long long>>
#define vi v<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()

#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define __lcm(a, b) ((a * b) / (__gcd(a, b)))
#define unq(v) (v).erase(unique(all((v)), (v).end()))

void precompute() {}
const int N = 100004;
int Log[N];
void log_eval(int n) {
  Log[0] = Log[1] = 0; // undefined for zero
  for (int i = 2; i <= n; i++) {
    Log[i] = Log[i / 2] + 1;
  }
}

void build(vvl &st, int lim, int n) {
  for (int j = 1; j <= lim; j++)
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[j].push_back(max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]));
    }
}
void solve() {
  in2(n, q);
  log_eval(n);
  int lim = Log[n];
  vvl st(lim + 1);
  vi arr(n);
  st[0].resize(n);
  for0(i, n) {
    in(val);
    st[0][i] = arr[i] = val;
  }
  build(st, lim, n);

  int cnt = 0;
  while (q--) {
    in2(l, r);
    l--, r -= 2;
    int sz = r - l + 1;
    int lg = Log[sz];
    cnt += (arr[l] >= max(st[lg][l], st[lg][r - (1 << lg) + 1]));
  }

  cout << cnt;
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
