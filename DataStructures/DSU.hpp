
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// UpdateByHeight
class DSU {
public:
  DSU(int n) : _arr(n, -1), _sz(n, 1) {}

  void unionSets(int root0, int root1) {
    int r0 = find(root0);
    int r1 = find(root1);
    if (r0 == r1)
      return;
    if (_sz[r0] < _sz[r1])
      swap(r0, r1);
    _sz[r1] += _sz[r0];
  }

  int find(int a) { return _arr[a] < 0 ? a : _arr[a] = find(_arr[a]); }

private:
  std::vector<int> _arr;
  std::vector<int> _sz;
};
