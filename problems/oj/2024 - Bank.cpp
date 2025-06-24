
/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: https://oj.uz/problem/view/IZhO14_bank
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

#define vec vector
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vi vector<int>
#define vll vector<ll>
#define all(v) begin(v), end(v)

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  in2(num_people, num_notes);
  int salaries[num_people];
  for (auto &x : salaries)
    cin >> x;
  int notes[num_notes];
  for (auto &x : notes)
    cin >> x;

  pair<int, int> dp[1 << num_notes]; // (leftover, last_person)
  memset(dp, -1, sizeof(dp));
  dp[0] = {0, 0};
  for (int mask = 0; mask < (1 << num_notes); mask++) {
    for (int note = 0; note < num_notes; note++) {
      if (!(mask & (1 << note)))
        continue;

      int without = mask ^ (1 << note);
      auto [prev_leftover, prev_last_person] = dp[without];

      int new_amt = prev_leftover + notes[note];
      int curr_target = salaries[prev_last_person];

      // Still not enough
      if (new_amt < curr_target) {
        dp[mask] = {new_amt, prev_last_person};
      }
      // If exactly enough
      else if (new_amt == curr_target) {
        dp[mask] = {0, prev_last_person + 1};
      }
    }

    // If we covered all people
    if (dp[mask].second == num_people) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
