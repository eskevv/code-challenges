#include <algorithm>
#include <vector>

auto remove_element(std::vector<int> &nums, int val) -> int {
  auto it_removed = std::remove(nums.begin(), nums.end(), val);
  nums.erase(it_removed, nums.end());
  return nums.size();
}