/*
  Name: Vedanta Somnathe
  Email: vpsomnathe@crimson.ua.edu
  Course Section: Spring 2026 CS 201 – 002
  Homework #: 0
  To Compile:
  To Run:
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
