#include <iostream>
#include <vector>
#include <string>

unsigned doTest() {
  unsigned n;
  std::cin >> n;
  unsigned num, sum = 0, even_sums = 0, odd_sums = 0, count = 0;
  for (unsigned i = 0 ; i < n ; ++i) {
    std::cin >> num;
    sum = (sum + num) % 2;
    if (sum) {
      odd_sums++;
      count += odd_sums - 1;
    } else {
      even_sums++;
      count += even_sums;
    }
  }
  return count;
}

int main() {
  unsigned test_case_num;
  std::cin >> test_case_num;
  for (unsigned i = 0 ; i < test_case_num ; ++i) {
    std::cout << doTest() << "\n";
  }
  return 0;
}
