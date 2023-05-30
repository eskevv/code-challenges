#pragma once

namespace {
struct RegexProblem {
  const char *expression;
  const char *input;
};
} // namespace

class Regex {
public:
  auto matches(const char *regexp, const char *text) -> int;

private:
  auto is_correct_char(const RegexProblem) -> bool;
  auto match_question(const RegexProblem) -> int;
  auto match_current(const RegexProblem) -> int;
  auto matchstar(int, RegexProblem) -> int;
};
