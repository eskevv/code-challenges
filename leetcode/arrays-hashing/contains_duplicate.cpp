#include <unordered_set>
#include <vector>

// Approach
// simply use hashmaps to check the count of each element

auto contains_duplicate(std::vector<int> &nums) -> bool {
  std::unordered_set<int> num_set;
  for (const auto &num : nums) {
    if (num_set.count(num) > 0)
      return true;
    num_set.insert(num);
  }
  return false;
}