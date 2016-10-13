#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct Species {
  std::string name;
  Species *parent;
  int age;

  Species() {};
  Species(std::string &n, Species *p, int a): name(n), parent(p), age(a) {};
};

void doTest() {
  int n, q, age, query_age;
  std::string name, s, p, query_name;
  std::cin >> n >> q;
  std::map<std::string, Species *> species_map;
  for (int i = 0 ; i < n ; ++i) {
    std::cin >> name >> age;
    Species *tmp = new Species(name, nullptr, age);
    species_map[name] = tmp;
  }
  for (int i = 0 ; i < n - 1 ; ++i) {
    std::cin >> s >> p;
    Species *parent = species_map[p];
    Species *offspring = species_map[s];
    offspring->parent = parent;
  }
  for (int i = 0 ; i < q ; ++i) {
    std::cin >> query_name >> query_age;
    Species *cur = species_map[query_name], *prev = cur;
    while (true) {
      if (!cur || cur->age > query_age) {
        std::cout << prev->name;
        if (i != q - 1) {
          std::cout << " ";
        }
        break;
      }
      prev = cur;
      cur = cur->parent;
    }
  }
  for (auto i: species_map) {
    delete i.second;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  unsigned test_count;
  std::cin >> test_count;
  for (unsigned i = 0 ; i < test_count ; ++i) {
    doTest();
    std::cout << "\n";
  }
  return 0;
}
