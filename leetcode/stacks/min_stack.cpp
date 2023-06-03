#include <algorithm>
#include <numeric>
#include <vector>

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    if (position >= capacity - 1) {
      capacity *= 2;
      int new_data[capacity];
      for (int x = 0; x < position; x++) {
        new_data[x] = data[x];
      }
      data = new_data;
    }
    data[++position] = val;
  }

  void pop() {
    if (position > 0)
      position--;
  }

  int top() {
    return data[position];
  }

  int getMin() {
    return std::accumulate(data, data + position, 0);
  }

private:
  int capacity{100};
  int position{0};
  int *data;
};