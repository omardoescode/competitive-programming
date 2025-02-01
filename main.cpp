#include "bits/stdc++.h"
#include <climits>
#include <cmath>

using namespace std;

#define ll long long
#define str string
#define oo (int)20000000
#define ull unsigned ll
#define pdi pair<double, int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define endl "\n"
#define in(a)                                                                  \
  int a;                                                                       \
  scanf("%d", &a);
#define in2(a, b)                                                              \
  int a, b;                                                                    \
  scanf("%d%d", &a, &b);
#define in3(a, b, c)                                                           \
  int a, b, c;                                                                 \
  scanf("%d%d%d", &a, &b, &c);

#define vec vector
#define veci vector<int>
#define vecll vector<ll>
#define all(v) v.begin(), v.end()

struct mltset {
  vector<ll> arr;

  mltset(int mx) {
    int n = 1 << (int)ceil(log2(mx + 1));
    arr.resize(n, 0);
    add(0, -1);
  }

  ll get(int i) const {
    ll res = 0;
    for (++i; i; i -= (i & -i))
      res += arr[i - 1];
    return res;
  }

  void add(int i, ll val) {
    for (++i; i <= arr.size(); i += (i & -i))
      arr[i - 1] += val;
  }

  // Inclusive
  ll get_range(int start, int end) { return get(end) - get(start - 1); }

  ll get_single_val(int i) { return get_range(i, i); }

  int lower_bound(ll target) const {
    int s = 0;
    for (int sz = arr.size() >> 1; sz; sz >>= 1)
      if (arr[s + sz - 1] < target)
        target -= arr[s + sz - 1], s += sz;
    return s;
  }

  void insert(int val, long long frequency = 1) { add(val, frequency); }
  void erase(int val, long long f) { add(val, -f); }
  void erase(int val) { add(val, get_single_val(val)); }
  int count(int val) const { return get(val); }
  int operator[](int i) const { return lower_bound(i); }
  size_t size() const { return count(arr.size() - 1) + 1; }
};

void solve() {
  mltset ms(1e6);
  in2(n, q);
  for (int i = 0; i < n; i++) {
    in(a);
    ms.insert(a);
  }

  while (q--) {
    in(k);
    if (k > 0)
      ms.insert(k);
    else
      ms.erase(ms[-k - 1], 1);
  }

  if (ms.size())
    printf("%d", ms[0]);
  else
    puts("0");
}
signed main() {
  int t = 1, c = 0;
  // scanf("%d", &t);
  while (t--)
    solve();
}
