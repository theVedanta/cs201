#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "insertionsort.cpp"
#include "mergesort.cpp"

int main(int argc, char *argv[]) {

  std::cout << "Problem Size\tTime Taken (seconds)" << std::endl;
  for (int size = 10; size <= 100000000; size *= 10) {

    int *a = new int[size];

    std::generate(a, a + size, std::rand);
    auto starttime = std::chrono::steady_clock::now();

    // -------------------- SORTS ----------------------------
    
    insertionsort(a, a + size);

    // int *temp = new int[size];
    // mergesort(a, a + size, temp);
    // delete[] temp;

    // std::sort(a, a + size);
    
    // -------------------- SORTS ----------------------------

    auto endtime = std::chrono::steady_clock::now();
    std::chrono::duration<double> timetaken = endtime - starttime;
    std::cout << size << "\t" << timetaken.count() << std::endl;

    delete[] a;
  }

  return 0;
}
