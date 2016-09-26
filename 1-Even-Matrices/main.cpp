#include <iostream>
#include <vector>
#include <string>

const unsigned MAX_SIZE = 200;
unsigned M[MAX_SIZE][MAX_SIZE];
unsigned row_sum[MAX_SIZE];

int oneRow(unsigned n) {
  unsigned sum = 0, even_sums = 0, odd_sums = 0, count = 0;
  for (unsigned i = 0 ; i < n ; ++i) {
    sum = sum ^ row_sum[i];
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

int doTest() {
  unsigned size, count = 0;
  std::cin >> size;
  for (unsigned i = 0 ; i < size ; ++i) {
    for (unsigned j = 0 ; j < size ; ++j) {
      std::cin >> M[i][j];
    }
  }
  for (unsigned i = 0 ; i < size ; ++i) {
    for (unsigned j = 0 ; j < size ; ++j) {
      row_sum[j] = 0;
    }
    for (unsigned j = i ; j < size ; ++j) {
      for (unsigned k = 0 ; k < size ; ++k) {
        row_sum[k] ^= M[j][k];
      }
      count += oneRow(size);
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
