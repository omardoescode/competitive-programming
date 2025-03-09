/**
 * بسم الله الرحمن الرحيم
 * Solved by: Omar Mohammad
 * Contact Me: https://www.linkedin.com/in/omardoescode/
 * My Github: https://github.com/omardoescode/
 *
 * Problem: D. I Love 1543
 * Contest: Codeforces Round 984 (Div. 3)
 * Judge: Codeforces
 * URL: https://codeforces.com/problemset/problem/2036/D
 * Memory Limit: 256
 * Time Limit: 2000
 * Start: Sun 02 Mar 2025 11:45:47 AM EET
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
#define __lcm(a, b) ((a * b) / (__gcd(a, b)))
#define unq(v) (v).erase(unique(all((v)), (v).end()))

#define L 0
#define R 1
#define U 2
#define D 3
void precompute() {}

vector<vector<int>> arr;
int dfs(int i, int j, int dir, int row, int col, int rsf) {
  int cnt = 0;
  if (arr[i][j] - '0' == 1)
    rsf = 1;
  if (rsf == 1 && arr[i][j] - '0' == 5)
    rsf = 2;
  if (rsf == 2 && arr[i][j] - '0' == 4)
    rsf = 3;
  if (rsf == 3 && arr[i][j] - '0' == 3)
    rsf = 0, cnt++;

  if (dir == L && j + 1 == col)
    dir = D;
  if (dir == D && i + 1 == row)
    dir = R;
  if (dir == R && j - 1 == -1)
    dir = U;
  if (dir == U && i - 1 == -1)
    return cnt;

  if (dir == L)
    return cnt + dfs(i, j + 1, dir, row, col, rsf);
  if (dir == D)
    return cnt + dfs(i + 1, j, dir, row, col, rsf);
  if (dir == R)
    return cnt + dfs(i, j - 1, dir, row, col, rsf);
  if (dir == U)
    return cnt + dfs(i - 1, j, dir, row, col, rsf);
}

void solve() {
  in2(n, m);
  arr.resize(n, vector<int>(m, 0));
  for (auto &r : arr)
    for (auto &v : r)
      cin >> v;

  int cnt = 0;
  for (int i = 0, row = n, col = m; row < 0 || col < 0;
       i++, row -= 2, col -= 2) {
    cnt += dfs(i, i, L, row, col, 0);
  }
  cout << cnt << endl;
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
