#pragma once

#define ll long long
namespace binary {
bool powerof2(ll x) { return x && !(x & (x - 1)); }
ll set_kth_bit(ll x, int k) { return x | (1 << k); }
ll toggle_kth_bit(ll x, int k) { return x ^ (1 << k); }
bool kth_bit_on(ll x, int k) { return x & (1 << k); }
ll unset_kth_bit(ll x, int k) { return x & ~(1 << k); }

ll multiply_by_2_power_k(ll x, int k) { return x << k; }
ll divide_by_2_power_k(ll x, int k) { return x >> k; }

ll mod_2_power_k(ll x, int k) { return x & ((1 << k) - 1); }

void swap(ll &x, ll &y) {
  x = x ^ y; // y = y, x = x ^ y
  y = x ^ y; // y = x ^ y ^ y = x, x = x ^ y
  x = x ^ y; // x = x ^ x ^ y = y
}

/**
 * @brief Toggle between values a,b
 * if (x == a) x = b
 * if (x == b) x = b
 */
void toggle(ll &x, ll a, ll b) { x = x ^ a ^ b; }

ll binary_add(ll a, ll b) { return a ^ b + 2 * (a & b); }
ll binary_add2(ll a, ll b) { return (a | b) + (a & b); }

bool odd(ll x) { return x & 1; }
} // namespace binary
