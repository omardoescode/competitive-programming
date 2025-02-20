/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 */
#include "bits/stdc++.h"
#include <algorithm>
#include <unordered_map>
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

const int N = 2e5 + 10;
struct Query {
  int s, e;
};
int s = 0, e = 0;
vec<int> arr;
int freq[N];
vec<Query> qs;
vec<int> qi;
vec<int> ans;
int cnt = 0;

void add(int x) {
  if (!freq[x]++)
    cnt++;
  // cout << "adding element at index " << x << " Current freq is " << freq[x]
  //      << endl;
}
void remove(int x) {
  if (!--freq[x])
    cnt--;
  // cout << "removing element at index " << x << " Current freq is " << freq[x]
  //      << endl;
}
void update(int i) {
  while (e <= qs[i].e)
    add(arr[e++]);
  while (s > qs[i].s)
    add(arr[--s]);
  while (e > qs[i].e + 1)
    remove(arr[--e]);
  while (s < qs[i].s)
    remove(arr[s++]);
}

void solve() {
  in2(n, q);
  int sq = sqrt(n);
  arr.resize(n);
  vec<int> vals(n);
  for (int i = 0; i < n; i++) {
    in(v);
    arr[i] = vals[i] = v;
  }
  sort(all(vals));
  vals.erase(unique(all(vals)), vals.end());

  unordered_map<int, int> compressed;
  for (int i = 0; i < vals.size(); i++)
    compressed[vals[i]] = i;
  for (int i = 0; i < n; i++)
    arr[i] = compressed[arr[i]];

  qs.resize(q);
  qi.resize(q);
  ans.resize(q);

  for (int i = 0; i < q; i++) {
    in2(a, b);
    a--, b--;
    qs[i] = {a, b};
    qi[i] = i;
  }
  sort(all(qi), [sq](int a, int b) {
    return make_pair(qs[a].s / sq, qs[a].e) < make_pair(qs[b].s / sq, qs[b].e);
  });
  for (int i = 0; i < q; i++) {
    update(qi[i]);
    ans[qi[i]] = cnt;
  }

  for (int i = 0; i < q; i++)
    cout << ans[i] << endl;
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
