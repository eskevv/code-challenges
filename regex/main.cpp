#include "regex.hpp"
#include <iostream>


auto main() -> int {
  Regex regex{};

  std::cout << regex.matches("Da*i", "Daaaaaaaaaaaaaaaaaaai") << std::endl;

  return 0;
}
