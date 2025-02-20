/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 */
#include "bits/stdc++.h"
#include <algorithm>

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
#define int long long
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

#define vec vector
#define veci vector<int>
#define vecll vector<ll>
#define all(v) v.begin(), v.end()

void precompute() {}

void solve() {
  in2(n, q);
  vec<int> arr(n), sorted(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sorted[i] = arr[i];
  }
  int sq = sqrt(n);
  for (int i = 0; i < n; i += sq)
    sort(sorted.begin() + i, sorted.begin() + min(n, i + sq));

  while (q--) {
    char op;
    cin >> op;
    if (op == 'M') {
      in2(i, m);
      i--;
      int bs = i / sq * sq;
      int p = lower_bound(sorted.begin() + bs, sorted.begin() + min(n, bs + sq),
                          arr[i]) -
              sorted.begin();
      arr[i] = sorted[p] = m;
      sort(sorted.begin() + bs, sorted.begin() + min(n, bs + sq));
    } else {
      in3(p, q, x);
      p--, q--;
      int sb = p / sq * sq, eb = q / sq * sq;
      int res = 0;

      if (sb == eb)
        for (int i = p; i <= q; i++)
          res += arr[i] <= x;
      else {
        for (int i = p; i < sb + sq; res += arr[i] <= x, i++)
          ;
        for (int i = eb; i <= q; res += arr[i] <= x, i++)
          ;
        for (int i = sb + sq; i < eb; i += sq) {
          res += upper_bound(sorted.begin() + i, sorted.begin() + i + sq, x) -
                 (sorted.begin() + i);
        }
      }

      cout << res << endl;
    }
  }
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
