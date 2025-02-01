#include <algorithm>
#include <stack>
#include <stdexcept>

template <typename T> class MonotonicStack {
public:
  void push(T val) {
    _st.emplace(val, _st.empty() ? val : std::max({val, _st.top().second}));
  }
  void pop() {
    if (_st.empty())
      throw std::runtime_error("Stack is empty");
    _st.pop();
  }
  T get_maximum() {
    if (_st.empty())
      throw std::runtime_error("Stack is empty");
    return _st.top().second;
  }

  bool empty() { return _st.empty(); }
  size_t size() { return _st.size(); }

  T top() {
    if (_st.empty())
      throw std::runtime_error("Stack is empty");
    return _st.top().first;
  }

private:
  std::stack<std::pair<T, T>> _st;
};
