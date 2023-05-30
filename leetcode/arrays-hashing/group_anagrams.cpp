#include "../global_headers.hpp"

template <typename T, typename K>
auto collect_values(std::unordered_map<K, std::vector<T>> map) -> std::vector<std::vector<T>> {
  std::vector<std::vector<T>> output;
  for (auto &&i : map) {
    output.push_back(i.second);
  }
  return output;
}

auto as_string(int *key, int size) -> std::string {
  std::string output{};
  for (size_t i = 0; i < size; i++) {
    output += *(key + i) + '#';
  }
  return output;
}

// valid input must be in range of [a-z]
auto create_key(const std::string &s) -> std::array<int, 26> {
  std::array<int, 26> key{};
  for (auto &&c : s) {
    key[c - 'a'] += 1;
  }
  return key;
}

auto group_anagrams(std::vector<std::string> &strs) -> std::vector<std::vector<std::string>> {
  std::unordered_map<std::string, std::vector<std::string>> map;
  for (auto &&s : strs) {
    std::array key = create_key(s);
    std::string string_key = as_string(key.data(), key.size());
    map[string_key].push_back(s);
  }
  return collect_values(map);
}