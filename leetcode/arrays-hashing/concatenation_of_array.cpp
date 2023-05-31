#include <vector>

auto get_concatenation(std::vector<int> &nums) -> std::vector<int> {
  std::vector<int> output(nums.size() * 2);
  for (auto i = 0; i < nums.size() * 2; i++) {
    output.push_back(nums.at(i % 3));
  }
  return output;
}