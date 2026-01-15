#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Include your sorts (assuming same directory)
#include "insertionsort.cpp" // Or compile separately without this
#include "mergesort.cpp"     // Or compile separately without this

using namespace std;

template <class RandomIt> void print(RandomIt start, RandomIt end) {
  while (start != end) {
    cout << *start << " ";
    ++start;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  int a0[] = {56, 23, 11, 64, 43, 99, 72, 88, 3, 31};
  array<int, 10> a1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  array<string, 10> a2 = {"ant", "bear", "cat",   "dog",    "elephant",
                          "fox", "goat", "horse", "iguana", "jaguar"};
  vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9, 7.4, 6.3, 8.5, 9.8, 10.1};

  cout << endl << endl;
  // Example: Test insertionsort on raw array
  insertionsort(a0, a0 + 10);
  cout << "insertion sort on a0: \t\t";
  print(a0, a0 + 10);

  // Example: Test mergesort on raw array (needs temp)
  int temp0[10];
  mergesort(a0, a0 + 10, temp0);
  cout << "mergesort on a0: \t\t";
  print(a0, a0 + 10);
  cout << "\n\n";

  // Example: Test insertionsort on array
  insertionsort(a1.begin(), a1.end());
  cout << "insertion sort on a1: \t\t";
  print(a1.begin(), a1.end());

  // Example: Test mergesort on array (needs temp)
  array<int, 10> temp1;
  mergesort(a1.begin(), a1.end(), temp1.begin());
  cout << "mergesort on a1: \t\t";
  print(a1.begin(), a1.end());
  cout << "\n\n";

  // Apply similar changes to a2 and v
  // For a2 (array<string, 10>), create array<string, 10>
  // temp2;
  cout << "insertion sort on a2: \t\t";
  print(a2.begin(), a2.end());

  array<string, 10> temp2;
  mergesort(a2.begin(), a2.end(), temp2.begin());
  cout << "mergesort on a2: \t\t";
  print(a2.begin(), a2.end());
  cout << "\n\n";

  // For v (vector<double>), create vector<double> tempv(v.size());
  insertionsort(v.begin(), v.end());
  cout << "insertion sort on v: \t\t";
  print(v.begin(), v.end());

  vector<double> tempv(v.size());
  mergesort(v.begin(), v.end(), tempv.begin());
  cout << "mergesort on v: \t\t";
  print(v.begin(), v.end());

  return 0;
}
