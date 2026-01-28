/*
  Name: Vedanta Somnathe

  Email: vpsomnathe@crimson.ua.edu

  Course Section: Spring 2026 CS 201 – 002

  Homework #: 0

  To Compile:
  With Driver file: g++ perftest.cpp insertionsort.cpp mergesort.cpp -o main
  Without: g++ insertionsort.cpp -o main

  To Run: ./main

  To Use:
  std::array<int, 10> temp1;
  mergesort(a1.begin(), a1.end(), temp1.begin());
*/

#include <algorithm>
using namespace std;

template <class RandomIt>
constexpr void mergesort(RandomIt first, RandomIt last, RandomIt tempstart) {
  auto len = last - first; // range length (requires random-access iterators)
  if (len < 2)             // base case: already sorted
    return;

  auto mid = first + len / 2; // split range in half

  mergesort(first, mid, tempstart);
  mergesort(mid, last,
            tempstart + (mid - first)); // offset temp buffer for right half

  RandomIt i = first, j = mid, k = tempstart;
  while (i != mid && j != last) { // merge two sorted halves into temp buffer
    if (*i <= *j) {               // stable: keep left element on ties
      *k++ = *i++;
    } else {
      *k++ = *j++;
    }
  }

  while (i != mid) // copy any remaining left-half elements
    *k++ = *i++;
  while (j != last) // copy any remaining right-half elements
    *k++ = *j++;

  std::copy(tempstart, tempstart + len,
            first); // write merged result back to original range
}
