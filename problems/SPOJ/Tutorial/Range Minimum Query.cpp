/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: $(PROBLEM)
 * Contest: $(CONTEST)
 * Judge: $(JUDGE)
 * URL: $(URL)
 * Memory Limit: $(MEMLIM)
 * Time Limit: $(TIMELIM)
 * Start: $(DATE)
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

const int N = 2e5 + 6, M = 18; // M = floor(lg(N))

int st[M][N], lg[N], n, arr[N];

void build() {
  lg[0] = -1; // undefined
  for (int i = 0; i < n; i++) {
    lg[i + 1] = lg[i] + !(i & (i + 1));
    st[0][i] = i;
  }

  for (int j = 1; 1 << j <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; i++) {
      int a = st[j - 1][i], b = st[j - 1][i + (1 << (j - 1))];
      st[j][i] = arr[a] < arr[b] ? a : b;
    }
}

int rmq(int s, int e) {
  int sz = e - s + 1;
  int l = lg[sz];
  int a = st[l][s], b = st[l][e - (1 << l) + 1];
  return arr[a] < arr[b] ? a : b;
}

void precompute() {}

void solve() {
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  build();
  while (q--) {
    in2(a, b);
    cout << arr[rmq(a, b)] << endl;
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
