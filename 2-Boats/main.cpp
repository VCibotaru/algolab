#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MAX_INT = 3000000;
struct Boat {
  int l;
  int p;
  int s;
  Boat(int len, int pos): l(len), p(pos), s(pos-len) {};
};

bool boatComparator(const Boat &a, const Boat &b) {
  return a.s < b.s;
}

int doTest() {
  int n, l, p, i;
  std::cin >> n;
  std::vector<Boat> boats;
  for (i = 0 ; i < n ; ++i) {
    std::cin >> l >> p;
    boats.push_back(Boat(l, p));
  }
  std::sort(boats.begin(), boats.end(), boatComparator);

  int count = 0, start, finish;
  int cur_pos = -MAX_INT;
  int best_boat_index;
  int best_boat_end;
  std::vector<bool> boat_taken(n, false);
  bool flag;
  while (true) {
    flag = false;
    best_boat_end = MAX_INT;
    for (i = 0 ; i < n ; ++i) {
      if (boat_taken[i]) {
        continue;
      }
      start = std::max(cur_pos, boats[i].s);
      finish = start + boats[i].l;
      if (start <= boats[i].p && boats[i].p <= finish &&
          finish < best_boat_end) {
        best_boat_end = finish;
        best_boat_index = i;
        flag = true;
      }
    }
    if (flag) {
      ++count;
      cur_pos = best_boat_end;
      boat_taken[best_boat_index] = true;
    }
    else {
      break;
    }
  }
  return count;
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
