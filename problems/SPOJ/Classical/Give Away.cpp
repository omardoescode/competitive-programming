/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Give Away
 * Contest: Classical
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/GIVEAWAY/
 * Memory Limit: 1536
 * Time Limit: 2000
 * Start: Sun 16 Feb 2025 07:16:48 AM EET
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

vector<int> arr, sorted;
int sq;
void solve() {
  in(n);
  sq = sqrt(n);
  arr.resize(n);
  sorted.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sorted[i] = arr[i];
  }

  for (int i = 0; i < n; i += sq) {
    sort(sorted.begin() + i, sorted.begin() + min(i + sq, n));
  }

  in(m);
  while (m--) {
    in3(type, a, b);
    if (type == 0) {
      in(c);
      a--, b--;
      int ab = a / sq * sq, bb = b / sq * sq;
      int ans = 0;
      if (ab == bb) {
        for (int i = a; i <= b; i++)
          ans += arr[i] >= c;
      } else {
        for (int i = a; i < ab + sq; i++)
          ans += arr[i] >= c;
        for (int i = bb; i <= b; i++)
          ans += arr[i] >= c;
        for (int i = ab + sq; i < bb; i += sq) { // Changed a+sq to ab+sq
          ans += sq - (lower_bound(sorted.begin() + i,
                                   sorted.begin() + min(i + sq, n), c) -
                       (sorted.begin() + i)); // Changed subtraction
        }
      }

      cout << ans << endl;
    } else if (type == 1) {
      a--;
      int ab = a / sq * sq;
      arr[a] = b;
      // Rebuild the entire block containing position a
      for (int i = ab, j = 0; i < min(ab + sq, n); i++, j++) {
        sorted[i] = arr[i];
      }
      sort(sorted.begin() + ab, sorted.begin() + min(ab + sq, n));
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
