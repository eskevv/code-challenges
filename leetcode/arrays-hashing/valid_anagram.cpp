#include <string>
#include <unordered_map>

// Approach:
// crate hashmaps out of each string to compare if they are anagrams

auto counter(std::string elements) -> std::unordered_map<char, int> {
  std::unordered_map<char, int> output;
  for (auto &&i : elements)
    output[i]++;
  return output;
}

auto is_anagram(const std::string &s, const std::string &t) -> bool {
  return counter(s) == counter(t);
}