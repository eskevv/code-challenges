#include "../global_headers.hpp"

auto two_sum(std::vector<int> &nums, int target) -> std::vector<int> {
  std::unordered_map<int, size_t> numbers;
  for (size_t i{0}; i < nums.size(); i++) {
    auto iter = numbers.find(target - nums[i]);
    if (iter != numbers.end())
      return std::vector<int>{static_cast<int>(i), static_cast<int>(iter->second)};
    numbers[nums[i]] = i; // register the index of the value
  }
  return std::vector<int>{};
}