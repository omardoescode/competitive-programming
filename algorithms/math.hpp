#include "bits/stdc++.h"
using namespace std;

#define ll long long

namespace number_thoery {
// O(sqrt(n))
void find_divisors_unsorted(ll num, vector<ll> &res) {
  res.clear();

  ll i;
  for (i = 1; i * i < num; i++)
    if (num % i == 0)
      res.push_back(i), res.push_back(num / i);

  if (i * i == num)
    res.push_back(i);
}

// NOTE: A number has an even number of divisors unless if it's a square root
int count_divisors(int value) {
  int sum = 0;
  int i;
  for (i = 1; i * i < value; i++)
    if (value % i == 0)
      sum += 2;

  if (i * i == value)
    sum += 1;

  return sum;
}
// O(sqrt(n))
void prime_factorization(long num, vector<ll> &res) {
  res.clear();

  while (num % 2 == 0)
    num /= 2, res.push_back(2);

  for (ll i = 3; i * i < num; i++)
    while (num % i == 0)
      num /= i, res.push_back(i);

  if (num > 1)
    res.push_back(num); // if there's a number that's greater than sqrt of num,
                        // then that number must be the remaining prime
}

ll mod(ll a, ll b) {
  ll res = a % b;
  if (res < 0)
    res += b;
  return res;
}

ll add_mod(ll a, ll b, ll m) { return (mod(a, m) + mod(b, m)) % m; }
ll sub_mod(ll a, ll b, ll m) { return (mod(a, m) - mod(b, m)) % m; }
ll mul_mod(ll a, ll b, ll m) { return (mod(a, m) * mod(b, m)) % m; }

ll pow_mod(ll a, ll b, ll m) {
  if (b == 0)
    return 1;
  if (b % 2 == 0) {
    ll x = pow_mod(a, b / 2, m);
    return mul_mod(x, x, m);
  } else {
    ll x = pow_mod(a, b / 2, m);
    ll xx = mul_mod(x, x, m);
    return mul_mod(xx, a, m);
  }
}

// Just use __gcd in all other cases
// This is a rough implementation to it
// O(log(min(a, b)))
ll euclidian_gcd(ll a, ll b) {
  if (a < b)
    swap(a, b);

  ll temp;
  while ((temp = a % b) != 0) {
    a = b;
    b = temp;
  }

  return b;
}

ll recursive_euclidian_algo(ll a, ll b) {
  if (b == 0)
    return a;
  if (a == 0)
    return b;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

bool is_prime(ll n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;

  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (ll i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}

bool prime[15000105];

void seive(int n) {
  prime[1] = prime[0] = 0;
  for (ll i = 2; i <= n; i++)
    prime[i] = 1;
  for (ll p = 2; p * p <= n; p++) {
    if (prime[p] == true)
      for (ll i = p * p; i <= n; i += p)
        prime[i] = false;
  }
}

} // namespace number_thoery
