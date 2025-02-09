
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <vector>
using namespace std;

class DSU {
public:
  DSU(size_t size) : count(0), _par(size), _rank(size) {}

  void reInit(size_t size) {
    _par.resize(size);
    _rank.resize(size);
    count = 0;
  }

  void make_set(int v) {
    _par[v] = v;
    _rank[v] = 0;
    count++;
  }

  /**
  * Without Path Compression
   int find_set(int v) {
    if (v == _par[v])
      return v;
    return find_set(_par[v]);
  }
  */
  int find_set(int v) {
    if (v == _par[v])
      return v;
    return _par[v] = find_set(_par[v]);
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    count--;
    if (a != b) {
      if (_rank[a] < _rank[b])
        swap(a, b);
      _par[b] = a;
      if (_rank[a] == _rank[b])
        _rank[a]++;
    }

    assert(count >= 0); // just to help in debugging
  }

private:
  vector<int> _par, _rank;
  int count;
};
