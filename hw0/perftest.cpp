
#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Include your sorts (assuming same directory)
#include "insertionsort.cpp" // Or compile separately without this
#include "mergesort.cpp"     // Or compile separately without this

using namespace std;

int main(int argc, char *argv[]) {

  cout << "Problem Size\tTime Taken (seconds)" << endl;
  for (int size = 10; size <= 100000000; size *= 10) {

    int *a = new int[size];

    generate(a, a + size, rand);
    auto starttime = chrono::steady_clock::now();

    // Test insertionsort (use for small sizes only)
    // insertionsort(a, a + size);

    // Test mergesort (add temp)
    // int *temp = new int[size];
    // mergesort(a, a + size, temp);
    // delete[] temp;

    // Test sort (original)
    sort(a, a + size);

    auto endtime = chrono::steady_clock::now();
    chrono::duration<double> timetaken = endtime - starttime;
    cout << size << "\t\t" << timetaken.count() << endl;

    delete[] a;
  }

  return 0;
}
