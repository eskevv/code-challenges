#include <algorithm>
#include <vector>

auto remove_duplicates(std::vector<int> &nums) -> int {
  auto unique_vec = std::unique(nums.begin(), nums.end());
  nums.erase(unique_vec, nums.end());
  return nums.size();
}