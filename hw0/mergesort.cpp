/*
  Name: Vedanta Somnathe
  Email: vpsomnathe@crimson.ua.edu
  Course Section: Spring 2026 CS 201 – 002
  Homework #: 0
  To Compile:
  To Run:
*/

#include <algorithm> // For std::copy

using namespace std;

template <class RandomIt>
constexpr void mergesort(RandomIt first, RandomIt last, RandomIt tempstart) {
  auto len = last - first;
  if (len < 2)
    return;
  auto mid = first + len / 2;
  mergesort(first, mid, tempstart);
  mergesort(mid, last, tempstart + (mid - first));
  RandomIt i = first, j = mid, k = tempstart;
  while (i != mid && j != last) {
    if (*i <= *j) {
      *k++ = *i++;
    } else {
      *k++ = *j++;
    }
  }
  while (i != mid)
    *k++ = *i++;
  while (j != last)
    *k++ = *j++;

  copy(tempstart, tempstart + len, first);
}
