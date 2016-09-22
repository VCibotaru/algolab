#include <iostream>
#include <vector>
#include <string>

int main() {
  unsigned test_cases_num, lines_num;
  float sum = 0, tmp;
  std::cin >> test_cases_num;
  for (unsigned i = 0 ; i < test_cases_num ; ++i) {
    sum = 0;
    std::cin >> lines_num;
    for (unsigned j = 0 ; j < lines_num ; ++j) {
      std::cin >> tmp;
      sum += tmp;
    }
    std::cout << sum << "\n";
  }
  return 0;
}
