#include <iostream>
#include <vector>
#include <string>
#include <utility>

int doTest() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for (int i = 0 ; i < n ; ++i) {
    std::cin >> v[i];
  }
  int last_pos = 0, cur_pos = 0, best_sum = 0, cur_sum = 0;
  bool best_set_yet = false;
  std::pair<int, int> best_pair;
  while (cur_pos < n) {
    if (cur_sum + v[cur_pos] > k) {
      if (!best_set_yet || abs(k - cur_sum) < abs(k - best_sum)) {
        best_sum = cur_sum;
        best_pair = std::pair<int, int>(last_pos, cur_pos - 1);
        best_set_yet = true;
      }
      while (cur_sum + v[cur_pos] > k && last_pos < cur_pos) {
        cur_sum = cur_sum - v[last_pos];
        last_pos += 1;
      }
    }
    cur_sum += v[cur_pos];
    cur_pos += 1;
  }
  if (!best_set_yet || abs(k - cur_sum) < abs(k - best_sum)) {
    best_sum = cur_sum;
    best_pair = std::pair<int, int>(last_pos, cur_pos - 1);
    best_set_yet = true;
  }
  std::cout << best_pair.first << " " << best_pair.second << "\n";
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int test_count;
  std::cin >> test_count;
  for (int i = 0 ; i < test_count ; ++i) {
    /* std::cout << doTest() << "\n"; */
    doTest();
  }
  return 0;
}
