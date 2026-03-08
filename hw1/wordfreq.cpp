/*
  Name: Vedanta Somnathe
  Email: vpsomnathe@crimson.ua.edu
  Course Section: Spring 2026 CS 201 – 002
  Homework #: 1
  Compile: g++ wordfreq.cpp -o wordfreq
  Run:     ./wordfreq < input1.txt
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

struct WordCount {
  string word;
  int count;
};

int main() {
  auto starttime = std::chrono::steady_clock::now();

  map<string, int> freq; // word -> count (O(log M) updates, worst-case)
  string text;
  const regex delim("\\s+");

  while (cin >> text) {
    auto begin = sregex_token_iterator(text.begin(), text.end(), delim, -1);
    auto end = sregex_token_iterator();
    for (sregex_token_iterator it = begin; it != end; ++it) {
      const string word = it->str();
      if (!word.empty())
        freq[word] = freq[word] + 1;
    }
  }

  // Move to vector for sorting by (count desc, word asc)
  vector<WordCount> items;
  items.reserve(freq.size());
  for (const auto &entry : freq) {
    items.push_back(WordCount{entry.first, entry.second});
  }

  sort(items.begin(), items.end(), [](const WordCount &a, const WordCount &b) {
    if (a.count != b.count)
      return a.count > b.count; // higher count first
    return a.word < b.word;     // tie: alphabetical
  });

  for (const auto &wc : items) {
    cout << wc.word << ": " << wc.count << "\n";
  }

  // Number of distinct words
  cout << "Distinct words: " << freq.size() << "\n";

  auto endtime = std::chrono::steady_clock::now();
  std::chrono::duration<double> timetaken = endtime - starttime;
  cerr << "Time Taken (seconds): " << timetaken.count() << "\n";

  return 0;
}
