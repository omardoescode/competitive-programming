/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 */
#include "bits/stdc++.h"
#include <queue>

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
  in2(n, m);
  vec<vec<int>> arr(n, vec<int>(m));
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (j != 0)
        arr[i][j] += arr[i][j - 1];
      sum += arr[i][j];
    }

    pq.emplace(arr[i][m - 1], sum);
  }

  int add = 0;
  int sum = 0;
  while (!pq.empty()) {
    auto [sum_of_elements, sum_of_sums] = pq.top();
    pq.pop();
    sum += add * m + sum_of_sums;
    add += sum_of_elements;
  }
  cout << sum << endl;
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  int t = 1, c = 0;
  cin >> t;
  precompute();
  while (t--)
    solve();
}
