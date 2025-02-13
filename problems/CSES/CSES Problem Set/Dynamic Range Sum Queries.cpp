/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 */
#include "bits/stdc++.h"
#include <utility>

using namespace std;

#define ll long long
#define str string
#define ooi (INT_MAX / 2)
#define ooll (LONG_LONG_MAX / 2)
#define ull unsigned ll
#define pdi pair<double, int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define int ll
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

#define vec vector
#define veci vector<int>
#define vecll vector<ll>
#define all(v) v.begin(), v.end()

void precompute() {}

void solve() {
  in2(n, q);
  int sq = sqrt(n);
  vec<int> arr(n);
  vec<int> sum(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum[i / sq] += arr[i];
  }

  while (q--) {
    in3(type, a, b);

    if (type == 1) {
      a--;
      sum[a / sq] -= arr[a];
      arr[a] = b;
      sum[a / sq] += b;
    } else if (type == 2) {
      a--, b--;
      int sb = a / sq, eb = b / sq;
      int res = 0;
      if (sb == eb)
        for (int i = a; i <= b; i++)
          res += arr[i];
      else {
        for (int i = a; i < (sb + 1) * sq; i++)
          res += arr[i];
        for (int i = sb + 1; i < eb; i++)
          res += sum[i];
        for (int i = eb * sq; i <= b; i++)
          res += arr[i];
      }
      cout << res << endl;
    }
  }
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  int t = 1, c = 0;
  // cin >> t;
  precompute();
  while (t--)
    solve();
}
