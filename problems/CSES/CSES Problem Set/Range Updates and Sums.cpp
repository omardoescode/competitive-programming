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
#define endl '\n'
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

vec<int> arr, sum, lazy_add, lazy_set;
int sq, n;
void push(int v) {
  if (lazy_set[v]) {
    for (int i = v * sq; i < min((v + 1) * sq, n); i++)
      arr[i] = lazy_set[v];
    lazy_set[v] = 0;
  }
  if (lazy_add[v]) {
    for (int i = v * sq; i < min((v + 1) * sq, n); i++)
      arr[i] += lazy_add[v];
    lazy_add[v] = 0;
  }
}

void solve() {
  cin >> n;
  in(q);
  sq = sqrt(n);
  arr.resize(n);
  sum.resize(n, 0);
  lazy_add.resize(n, 0);
  lazy_set.resize(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum[i / sq] += arr[i];
  }

  while (q--) {
    in3(op, s, e);
    s--, e--;
    int sb = s / sq, eb = e / sq;

    push(sb), push(eb);

    if (op == 1) {
      in(x);
      if (sb == eb) {
        for (int i = s; i <= e; i++) {
          arr[i] += x;
          sum[sb] += x;
        }
      } else {
        for (int i = s; i < (sb + 1) * sq; i++) {
          arr[i] += x, sum[sb] += x;
        }
        for (int i = (sb + 1); i < eb; i++) {
          lazy_add[i] += x, sum[i] += sq * x;
        }
        for (int i = eb * sq; i <= e; i++) {
          arr[i] += x, sum[eb] += x;
        }
      }
    } else if (op == 2) {
      in(x);
      if (sb == eb) {
        for (int i = s; i <= e; i++) {
          sum[sb] -= arr[i];
          arr[i] = x;
          sum[sb] += x;
        }
      } else {
        for (int i = s; i < (sb + 1) * sq; i++) {
          sum[sb] -= arr[i];
          arr[i] = x;
          sum[sb] += x;
        }
        for (int i = (sb + 1); i < eb; i++) {
          lazy_set[i] = x;
          lazy_add[i] = 0;
          sum[i] = sq * x;
        }
        for (int i = eb * sq; i <= e; i++) {
          sum[eb] -= arr[i];
          arr[i] = x;
          sum[eb] += x;
        }
      }
    } else {
      int res = 0;
      if (sb == eb) {
        for (int i = s; i <= e; i++) {
          res += arr[i];
        }
      } else {
        for (int i = s; i < (sb + 1) * sq; i++)
          res += arr[i];
        for (int i = (eb)*sq; i <= e; i++)
          res += arr[i];
        for (int i = sb + 1; i < eb; i++)
          res += sum[i];
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
