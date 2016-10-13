#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct Species {
  std::string name;
  int age;
  std::vector<Species *> children;
  // this vector will hold every 2^n ancestor on the way from every species
  // to LUCA
  std::vector<Species *> ancestors; 
  bool visited; // for DFS

  Species() {};
  Species(std::string &n, int a): name(n), age(a), visited(false) {};
  void addChild(Species *child) {
    children.push_back(child);
  }
  void addAncestor(Species *anc) {
    ancestors.push_back(anc);
  }
};

typedef std::map<std::string, Species *> SpeciesMap;

Species *readSpecies(int n, SpeciesMap &species_map) {
  int age, max_age = 0;
  std::string name;
  Species *luca;
  for (int i = 0 ; i < n ; ++i) {
    std::cin >> name >> age;
    Species *tmp = new Species(name, age);
    species_map[name] = tmp;
    if (age > max_age) {
      luca = tmp;
      max_age = age;
    }
  }
  return luca;
}

void readRelations(int n, SpeciesMap &species_map) {
  std::string s, p;
  for (int i = 0 ; i < n - 1 ; ++i) {
    std::cin >> s >> p;
    Species *parent = species_map[p];
    Species *offspring = species_map[s];
    parent->addChild(offspring);
  }
}

void DFS(Species *cur, std::vector<Species *> &prev) {
  cur->visited = true;
  unsigned i = 1;
  unsigned n = prev.size();
  while (n - i < prev.size()) {
    cur->addAncestor(prev[n - i]);
    i *= 2;
  }
  // should i do it?
  if (n > 0 && prev[0] != cur->ancestors.back()) {
    cur->addAncestor(prev[0]);
  }
  prev.push_back(cur);
  for (Species *child: cur->children) {
    DFS(child, prev);
  }
  prev.pop_back();
}

std::string binSearch(Species *cur, int age) {
  std::vector<Species *> &ancestors = cur->ancestors;
  if (ancestors.size() == 0 ||  ancestors[0]->age > age) {
    return cur->name;
  }
  Species *last = ancestors[0];
  for (unsigned i = 1 ; i < ancestors.size() ; ++i) {
    if (ancestors[i]->age > age) {
      break;
    }
    last = ancestors[i];
  }
  return binSearch(last, age);
}

void doTest() {
  int n, q, query_age; 
  std::string query_name;
  SpeciesMap species_map;
  std::vector<Species *> tmp;

  std::cin >> n >> q;
  Species *luca = readSpecies(n, species_map);
  readRelations(n, species_map);
  DFS(luca, tmp);

  for (int i = 0 ; i < q ; ++i) {
    std::cin >> query_name >> query_age;
    Species *cur = species_map[query_name];
    std::cout << binSearch(cur, query_age);
    if (i != q - 1) {
      std::cout << " ";
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
