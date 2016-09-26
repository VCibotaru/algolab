#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

#define POS(n) n - 1
#define COIN(n) n + 1

std::set<unsigned> intersectSets(std::set<unsigned> &a, std::set<unsigned> &b) {
  std::set<unsigned> res;
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), 
      std::inserter(res, res.end()));
  return res;
}

unsigned doTest() {
  char sign;
  unsigned coin_num, weighning_num, coins_on_pan, tmp;
  std::cin >> coin_num >> weighning_num;
  std::set<unsigned> light_coins, heavy_coins;

  for (unsigned i = 0 ; i < coin_num ; ++i) {
    light_coins.insert(i);
    heavy_coins.insert(i);
  }
  for (unsigned i = 0 ; i < weighning_num ; ++i) {
    std::cin >> coins_on_pan;
    std::vector<unsigned> left, right;
    for (unsigned j = 0 ; j < coins_on_pan ; ++j) {
      std::cin >> tmp;
      left.push_back(POS(tmp));
    }
    for (unsigned j = 0 ; j < coins_on_pan ; ++j) {
      std::cin >> tmp;
      right.push_back(POS(tmp));
    }
    std::cin >> sign;
    if (sign == '=') {
      for (unsigned j = 0 ; j < coins_on_pan ; ++j) {
        light_coins.erase(left[j]);
        light_coins.erase(right[j]);
        heavy_coins.erase(left[j]);
        heavy_coins.erase(right[j]);
      }
      continue;
    } 
    std::set<unsigned> left_coins(left.begin(), left.end());
    std::set<unsigned> right_coins(right.begin(), right.end());
    if (sign == '>') {
      heavy_coins = intersectSets(left_coins, heavy_coins);
      light_coins = intersectSets(right_coins, light_coins);
    }
    else {
      heavy_coins = intersectSets(right_coins, heavy_coins);
      light_coins = intersectSets(left_coins, light_coins);
    }
  }
  /* std::cout << "light coins:\n"; */
  /* for (unsigned i: light_coins) { */
  /*   std::cout << COIN(i) << "\n"; */
  /* } */
  /* std::cout << "heavy coins:\n"; */
  /* for (unsigned i: heavy_coins) { */
  /*   std::cout << COIN(i) << "\n"; */
  /* } */
  if (light_coins.size() + heavy_coins.size() != 1) {
    std::set<unsigned> tmp = intersectSets(light_coins, heavy_coins);
    if (tmp.size() != 1) {
      return 0;
    } else {
      return COIN(*(tmp.begin()));
    }
  }
  if (light_coins.size()) {
    return COIN(*(light_coins.begin()));
  }
  return COIN(*(heavy_coins.begin()));
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
