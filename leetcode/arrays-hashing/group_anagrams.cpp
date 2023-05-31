#include <string>
#include <unordered_map>
#include <vector>

template <typename T, typename K>
auto collect_values(std::unordered_map<K, std::vector<T>> map) -> std::vector<std::vector<T>> {
  std::vector<std::vector<T>> output;
  for (auto &&i : map) {
    output.push_back(i.second);
  }
  return output;
}

// valid input must be in range of [a-z]
auto create_key(const std::string &s) -> std::string {
  const int size = 26;
  int key[size]{};
  for (auto &&c : s) {
    key[c - 'a']++;
  }
  std::string output{};
  for (size_t i = 0; i < size; i++) {
    output += key[i] + '#';
  }
  return output;
}

auto group_anagrams(std::vector<std::string> &strs) -> std::vector<std::vector<std::string>> {
  std::unordered_map<std::string, std::vector<std::string>> map;
  for (auto &&s : strs) {
    map[create_key(s)].push_back(s);
  }
  return collect_values(map);
}