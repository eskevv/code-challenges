#include <unordered_map>
#include <vector>

auto top_k_frequent(std::vector<int> &nums, int k) -> std::vector<int> {
  std::unordered_map<int, int> occurances{};
  std::vector<int> frequency[nums.size() + 1];
  std::vector<int> output{};

  for (auto &&i : nums) {
    occurances[i]++;
  }
  for (auto &&i : occurances) {
    frequency[i.second].push_back(i.first);
  }
  for (auto i = nums.size() + 1; i > 0; --i) {
    for (auto &&m : frequency[i]) {
      output.push_back(m);
      if (output.size() == k)
        return output;
    }
  }
  return output;
}