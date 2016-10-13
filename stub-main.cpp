#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int doTest() {
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  unsigned test_count;
  std::cin >> test_count;
  for (unsigned i = 0 ; i < test_count ; ++i) {
    std::cout << doTest() << "\n";
  }
  return 0;
}
