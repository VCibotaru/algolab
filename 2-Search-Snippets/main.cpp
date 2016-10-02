#include <iostream>
#include <vector>
#include <string>
#include <set>

typedef std::pair<unsigned, unsigned> IntPair;

void print_set(std::vector<int> &vec) {
  for (unsigned i = 0 ; i < vec.size() ; ++i) {
    std::cout << "(" << i << ", " << vec[i] << ") ";
  }
  std::cout << "\n";
}

bool hasAllWords(std::vector<int> &vec) {
  for (int x: vec) {
    if (x == 0) {
      return false;
    }
  }
  return true;
}

unsigned doTest() {
  unsigned n, numbers_count = 0, tmp;
  std::cin >> n;
  std::vector<unsigned> M(n);
  std::set<IntPair> numbers_set;
  for (unsigned i = 0 ; i < n ; ++i) {
    std::cin >> M[i];
  }
  for (unsigned i = 0 ; i < n ; ++i) {
    for (unsigned j = 0 ; j < M[i]; ++j) {
      std::cin >> tmp;
      numbers_set.insert(IntPair(tmp, i));
    }
    numbers_count += M[i];
  }
  // numbers_vector is an array of:
  // <position_in_file, word_at_the_position> 
  // as all positions are unique, it will be properly sorted here
  std::vector<IntPair> numbers_vector(numbers_set.begin(), numbers_set.end());
  std::vector<int> current_words(n);
  unsigned left = 0, right = 0, 
      best_result = numbers_vector.back().first - numbers_vector[0].first + 1;
  current_words[numbers_vector[0].second] = 1;
  while (right < numbers_vector.size()) {
    /* std::cout << left << " " << right << "\n"; */
    /* print_set(current_words); */
    if (hasAllWords(current_words)) {
      // the set already contains all numbers
      unsigned cur_result = 
        numbers_vector[right].first - numbers_vector[left].first + 1;
      if (cur_result < best_result) {
        best_result = cur_result;
      }
      --current_words[numbers_vector[left].second];
      ++left;
    }
    else {
      if (++right == numbers_vector.size()) {
        break;
      }
      ++current_words[numbers_vector[right].second];
    }
  }
  /* while (hasAllWords(current_words) && left < numbers_vector.size()) { */
  /*     --current_words[numbers_vector[left].second]; */
  /*     ++left; */
  /* } */
  /* unsigned cur_result = */ 
  /*   numbers_vector[right].first - numbers_vector[left].first + 1; */
  /* if (cur_result < best_result) { */
  /*   best_result = cur_result; */
  /* } */
  return best_result;
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
