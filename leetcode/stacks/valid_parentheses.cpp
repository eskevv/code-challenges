#include <stack>
#include <string>
#include <unordered_map>

std::unordered_map<char, char> closing_pairs{
    {')', '('},
    {'}', '{'},
    {']', '['},
};

auto is_valid(const std::string &s) {
  std::stack<char> inputs{};
  for (auto &&c : s) {
    if (c == '(' || c == '[' || c == '{')
      inputs.push(c);
    else {
      if (inputs.empty() || inputs.top() != closing_pairs[c])
        return false;
      inputs.pop();
    }
  }
  return inputs.empty();
}
