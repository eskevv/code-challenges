#include <numeric>
#include <string>
#include <vector>

void apply_operation(std::vector<int> &scores, const std::string &o) {
  if (o == "+" && scores.size() >= 2)
    scores.push_back(scores[scores.size() - 2] + scores[scores.size() - 1]);
  else if (o == "D" && !scores.empty())
    scores.push_back(scores.back() * 2);
  else if (o == "C" && !scores.empty())
    scores.pop_back();
  else
    scores.push_back(std::stoi(o));
}

auto cal_points(std::vector<std::string> &operations) -> int {
  std::vector<int> scores{};
  for (auto &&i : operations) {
    apply_operation(scores, i);
  }
  return std::accumulate(scores.begin(), scores.end(), 0);
}