#include "MonotonicStack.hpp"

template <typename T> class MonotonicQueue {
public:
  void push(T val) { _in.push(val); }
  void pop() {
    if (_out.empty())
      _move_elements();
    _out.pop();
  }

  size_t size() { return _in.size() + _out.size(); }

  bool empty() { return _in.empty() && _out.empty(); }

  T front() {
    if (_out.empty())
      _move_elements();
    return _out.top();
  }

  T get_maximum() {
    if (empty())
      throw std::runtime_error("Queue is empty");
    if (_in.empty())
      return _out.get_maximum();
    if (_out.empty())
      return _in.get_maximum();
    return std::max(_in.get_maximum(), _out.get_maximum());
  }

private:
  void _move_elements() {
    while (!_in.empty()) {
      _out.push(_in.top());
      _in.pop();
    }
  }

private:
  MonotonicStack<T> _in, _out;
};
