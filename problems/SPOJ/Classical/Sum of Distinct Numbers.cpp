/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: Sum of Distinct Numbers
 * Contest: Classical
 * Judge: SPOJ
 * URL: https://www.spoj.com/problems/XXXXXXXX/
 * Memory Limit: 1536
 * Time Limit: 1000
 * Start: Sun 23 Feb 2025 06:48:45 PM EET
 */
#include "bits/stdc++.h"
#include <tuple>
#include <unordered_map>

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
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()

#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define __lcm(a, b) (((a) * (b)) / (__gcd((a), (b))))
#define unq(v) (v).erase(unique(all((v)), (v).end()))
void precompute() {}
const int N = 5e4 + 6, Q = 1e5 + 5;
struct answer_query {
  ll start, end, time, idx;
};
struct update_query {
  ll pos, old_val, val;
};
answer_query queries[Q];
update_query updates[Q];
int cs = 0, ce = 0, ct = 0;
vi arr;
int freq[N + Q],
    decompress[N + Q]; // decompress is used to go back from value to key in
                       // compression
ll sum = 0;
int ans[Q];

void add(int value) {
  freq[value]++;
  if (freq[value] == 1)
    sum += decompress[value];
}
void remove(int value) {
  freq[value]--;
  if (freq[value] == 0)
    sum -= decompress[value];
}
void answer(const answer_query &query) {
  auto &[start, end, time, idx] = query;
  // update time
  // Here the range is from [0, ct)
  while (ct < time) {
    ct++;
    if (updates[ct].pos >= cs && updates[ct].pos < ce) {
      remove(arr[updates[ct].pos]);
      add(updates[ct].val);
    }
    arr[updates[ct].pos] = updates[ct].val;
  }
  while (ct > time) {
    if (updates[ct].pos >= cs && updates[ct].pos < ce) {
      remove(arr[updates[ct].pos]);
      add(updates[ct].old_val);
    }
    arr[updates[ct].pos] = updates[ct].old_val;
    ct--;
  }

  while (ce <= end) {
    add(arr[ce]);
    ce++;
  }
  while (cs > start) {
    cs--;
    add(arr[cs]);
  }
  while (ce > end + 1) {
    ce--;
    remove(arr[ce]);
  }
  while (cs < start) {
    remove(arr[cs]);
    cs++;
  }

  // answer here
  ans[idx] = sum;
}
void solve() {
  in(n);
  unordered_map<int, int> mp;
  arr.resize(n);
  for0(i, n) {
    cin >> arr[i];
    mp[arr[i]]; // This just inserts them with value equal to 0
  }
  in(q);
  int numofQ = 0, numofU = 0;
  for (int i = 0; i < q; i++) {
    char type;
    cin >> type;
    in2(x, y);
    if (type == 'Q') {
      x--, y--;
      queries[numofQ] = {x, y, numofU, numofQ};
      numofQ++;
    } else {
      x--, numofU++, ct++;
      updates[numofU] = {x, arr[x], y};
      arr[x] = y;
      mp[y]; // insert with value equal to 0
    }
  }

  int values = 0;
  for (auto &p : mp) {
    p.second = values;
    decompress[p.second] = p.first; // vals for decompression
    values++;                       // update for next entry
  }

  // compress
  for0(i, n) arr[i] = mp[arr[i]];
  for1(i, numofU) {
    auto &v = updates[i];
    v.val = mp[v.val];
    v.old_val = mp[v.old_val];
  }

  int b = pow(2LL * n * n, 1.0 / 3);
  sort(queries, queries + numofQ,
       [b](const answer_query &x, const answer_query &y) {
         return make_tuple(x.start / b, x.end / b, x.time) <
                make_tuple(y.start / b, y.end / b, y.time);
       });

  for0(i, numofQ) answer(queries[i]);

  for0(i, numofQ) cout << ans[i] << endl;
}

signed main() {
  FASTIO;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   // freopen("output.txt", "w", stdout);
  // #endif
  solve();
}
