#include "regex.hpp"

auto Regex::matches(const char *regexp, const char *text) -> int {
  if (regexp[0] == '^')
    return match_current(RegexProblem{regexp + 1, text});
  do {
    if (match_current(RegexProblem{regexp, text}))
      return 1;
  } while (*text++ != '\0');
  return 0;
}

auto Regex::is_correct_char(const RegexProblem p) -> bool {
  return p.expression[0] == '.' || p.expression[0] == *p.input;
}

auto Regex::match_question(const RegexProblem p) -> int {
  // move text forward if there is a match or stay if there is no match
  const char *text_matcher = is_correct_char(p) ? p.input + 1 : p.input;
  return match_current(RegexProblem{p.expression + 2, text_matcher});
}

auto Regex::match_current(const RegexProblem p) -> int {
  if (p.expression[0] == '\0')
    return 1;
  if (p.expression[1] == '*')
    return matchstar(p.expression[0], RegexProblem{p.expression + 2, p.input});
  if (p.expression[1] == '?')
    return match_question(RegexProblem{p.expression, p.input});
  if (p.expression[0] == '$' && p.expression[1] == '\0')
    return *p.input == '\0';
  if (*p.input != '\0' && is_correct_char(p))
    return match_current(RegexProblem{p.expression + 1, p.input + 1});
  return 0;
}

auto Regex::matchstar(int c, RegexProblem p) -> int {
  do {
    if (match_current(RegexProblem{p.expression, p.input}))
      return 1;
  } while (*p.input != '\0' && (*p.input++ == c || c == '.'));
  return 0;
}