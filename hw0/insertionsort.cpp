/*
  Name: Vedanta Somnathe

  Email: vpsomnathe@crimson.ua.edu

  Course Section: Spring 2026 CS 201 – 002

  Homework #: 0

  To Compile:
  With Driver file: g++ perftest.cpp insertionsort.cpp mergesort.cpp -o main
  Without: g++ insertionsort.cpp -o main

  To Run: ./main

  To Use:   insertionsort(a1.begin(), a1.end());
*/

template <class RandomIt>
constexpr void insertionsort(RandomIt first, RandomIt last) {
  for (RandomIt i = first + 1; i != last; ++i) {
    auto key = *i;
    RandomIt j = i;
    while (j > first && *(j - 1) > key) {
      *j = *(j - 1);
      --j;
    }
    *j = key;
  }
}
