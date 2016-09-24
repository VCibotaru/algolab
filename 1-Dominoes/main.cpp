#include <iostream>
#include <vector>
#include <string>

int doTest() {
  unsigned max_index = 1, dom_count, cur_height;
  std::cin >> dom_count;
  for (unsigned i = 1 ; i <= dom_count ; ++i) {
    std::cin >> cur_height;
    if (i <= max_index) {
      max_index = std::max(cur_height + i - 1, max_index);
    }
  }
  return std::min(max_index, dom_count);
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
