/*
  Name: Vedanta Somnathe
  Email: vpsomnathe@crimson.ua.edu
  Course Section: Spring 2026 CS 201 – 002
  Homework #: 2
  To Compile: g++ wordfreq.cpp -o wordfreq
  To Run:     ./wordfreq < input1.txt
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include "ST.hpp"

struct WordCount {
  std::string word;
  int count;
};

int main() {
  auto starttime = std::chrono::steady_clock::now();

  ST<std::string, int> freq;
  std::string text;
  const std::regex delim("\\s+");

  while (std::cin >> text) {
    auto begin =
        std::sregex_token_iterator(text.begin(), text.end(), delim, -1);
    auto end = std::sregex_token_iterator();
    for (std::sregex_token_iterator it = begin; it != end; ++it) {
      const std::string word = it->str();
      if (!word.empty()) {
        freq[word] = freq[word] + 1;
      }
    }
  }

  // Convert ST to vector of (key, value) pairs
  std::vector<std::pair<std::string, int>> pairs = freq.toVector();

  // Move to WordCount vector for sorting by (count desc, word asc)
  std::vector<WordCount> items;
  items.reserve(pairs.size());
  for (const auto &entry : pairs) {
    items.push_back(WordCount{entry.first, entry.second});
  }

  std::sort(items.begin(), items.end(),
            [](const WordCount &a, const WordCount &b) {
              if (a.count != b.count)
                return a.count > b.count; // higher count first
              return a.word < b.word;     // tie: alphabetical
            });

  for (const auto &wc : items) {
    std::cout << wc.word << ": " << wc.count << "\n";
  }

  // Number of distinct words
  std::cout << "Distinct words: " << freq.size() << "\n";

  auto endtime = std::chrono::steady_clock::now();
  std::chrono::duration<double> timetaken = endtime - starttime;
  std::cerr << "Time Taken (seconds): " << timetaken.count() << "\n";

  return 0;
}
