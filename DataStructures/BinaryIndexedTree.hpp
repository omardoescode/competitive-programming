template <typename T>
// assumes 0-indexing
struct BIT {
  vector<T> arr;

  BIT(int n) {
    n = 1 << (int)ceil(log2(n));
    arr.resize(n, 0);
  }

  BIT(const vector<T> &a) {
    int n = 1 << (int)ceil(log2(a.size()));
    cout << n << endl;
    arr.resize(n, 0);
    for (int i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  // This would return the sum of all numbers from 0 to `i`
  T get(int i) {
    T res = 0;
    for (++i; i; i -= (i & -i))
      res += arr[i - 1];
    return res;
  }

  void add(int i, T val) {
    for (++i; i <= arr.size(); i += (i & -i))
      arr[i - 1] += val;
  }

  // no need to check for `get(-1)` since it returns -1
  // Inclusive
  T get_range(int start, int end) { return get(end) - get(start - 1); }

  // Get one single value
  T get_single_val(int i) { return get_range(i, i); }

  int lower_bound(T target) const {
    int s = 0;
    for (int sz = arr.size() >> 1; sz; sz >>= 1)
      if (arr[s + sz - 1] < target)
        target -= arr[s + sz - 1], s += sz;
    return s;
  }

  int size() const { return arr.size(); }
}
