#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Include your sorts (assuming same directory)
#include "insertionsort.cpp" // Or compile separately without this
#include "mergesort.cpp"     // Or compile separately without this

template <class RandomIt> void print(RandomIt start, RandomIt end) {
  while (start != end) {
    std::cout << *start << " ";
    ++start;
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  int a0[] = {56, 23, 11, 64, 43, 99, 72, 88, 3, 31};
  std::array<int, 10> a1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::array<std::string, 10> a2 = {"ant",      "bear",  "cat",  "dog",
                                    "elephant", "fox",   "goat", "horse",
                                    "iguana",   "jaguar"};
  std::vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9, 7.4, 6.3, 8.5, 9.8, 10.1};

  std::cout << "=== a0 (raw array<int>) ===" << std::endl;
  // Example: Test insertionsort on raw array
  insertionsort(a0, a0 + 10);
  print(a0, a0 + 10);

  // Example: Test mergesort on raw array (needs temp)
  int temp0[10];
  mergesort(a0, a0 + 10, temp0);
  print(a0, a0 + 10);

  // Example: Test std::sort on raw array
  std::sort(a0, a0 + 10);
  print(a0, a0 + 10);

  std::cout << "=== a1 (std::array<int, 10>) ===" << std::endl;
  // Example: Test insertionsort on std::array
  insertionsort(a1.begin(), a1.end());
  print(a1.begin(), a1.end());

  // Example: Test mergesort on std::array (needs temp)
  std::array<int, 10> temp1;
  mergesort(a1.begin(), a1.end(), temp1.begin());
  print(a1.begin(), a1.end());

  // Example: Test std::sort on std::array
  std::sort(a1.begin(), a1.end());
  print(a1.begin(), a1.end());

  std::cout << "=== a2 (std::array<std::string, 10>) ===" << std::endl;
  // Example: Test insertionsort on std::array<std::string, 10>
  insertionsort(a2.begin(), a2.end());
  print(a2.begin(), a2.end());

  // Example: Test mergesort on std::array<std::string, 10> (needs temp)
  std::array<std::string, 10> temp2;
  mergesort(a2.begin(), a2.end(), temp2.begin());
  print(a2.begin(), a2.end());

  // Example: Test std::sort on std::array<std::string, 10>
  std::sort(a2.begin(), a2.end());
  print(a2.begin(), a2.end());

  std::cout << "=== v (std::vector<double>) ===" << std::endl;
  // Example: Test insertionsort on std::vector<double>
  insertionsort(v.begin(), v.end());
  print(v.begin(), v.end());

  // Example: Test mergesort on std::vector<double> (needs temp)
  std::vector<double> tempv(v.size());
  mergesort(v.begin(), v.end(), tempv.begin());
  print(v.begin(), v.end());

  // Example: Test std::sort on std::vector<double>
  std::sort(v.begin(), v.end());
  print(v.begin(), v.end());

  return 0;
}
