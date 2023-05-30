#include "../global_headers.hpp"

auto contains_duplicate(std::vector<int> &nums) -> bool {
  std::unordered_set<int> numSet;
  for (const auto &num : nums) {
    if (numSet.count(num) > 0) {
      return true;
    }
    numSet.insert(num);
  }
  return false;
}