/*
Name: Vedanta Somnathe
Email: vpsomnathe@crimson.ua.edu
Course Section: Spring 2026 CS 201
Homework #: 3

To Compile:
g++ -std=c++20 -O2 hw3.cpp -o hw3

To Run:
./hw3 <db file> <query file>

Example:
./hw3 dbfile1.txt query.txt
*/

#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Removes leading/trailing whitespace from a string.
static string trim(const string &s) {
  size_t start = 0;
  while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) {
    ++start;
  }

  size_t end = s.size();
  while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) {
    --end;
  }

  return s.substr(start, end - start);
}

// Splits a line by "/" into tokens.
static vector<string> splitBySlash(const string &line) {
  vector<string> tokens;
  stringstream ss(line);
  string token;

  while (getline(ss, token, '/')) {
    token = trim(token);
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }

  return tokens;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <db file> <query file>\n";
    return 1;
  }

  const string dbFileName = argv[1];
  const string queryFileName = argv[2];

  ifstream dbFile(dbFileName);
  if (!dbFile.is_open()) {
    cout << "Unable to open DB file: " << dbFileName << "\n";
    return 1;
  }

  // movie -> actors
  unordered_map<string, vector<string>> movieToActors;
  // actor -> movies
  unordered_map<string, vector<string>> actorToMovies;

  string line;
  size_t recordCount = 0;

  // Time only data structure creation/parsing.
  const auto createStart = chrono::high_resolution_clock::now();

  while (getline(dbFile, line)) {
    if (line.empty()) {
      continue;
    }

    vector<string> parts = splitBySlash(line);
    if (parts.empty()) {
      continue;
    }

    const string &movie = parts[0];
    if (movie.empty()) {
      continue;
    }

    ++recordCount;

    // Ensure movie key exists.
    auto &actors = movieToActors[movie];

    // Remaining tokens are actors.
    for (size_t i = 1; i < parts.size(); ++i) {
      const string &actor = parts[i];
      if (actor.empty()) {
        continue;
      }

      actors.push_back(actor);
      actorToMovies[actor].push_back(movie);
    }
  }

  const auto createEnd = chrono::high_resolution_clock::now();
  dbFile.close();

  ifstream queryFile(queryFileName);
  if (!queryFile.is_open()) {
    cout << "Unable to open query file: " << queryFileName << "\n";
    return 1;
  }

  // Time query searching/retrieval.
  const auto searchStart = chrono::high_resolution_clock::now();

  string query;
  while (getline(queryFile, query)) {
    query = trim(query);
    if (query.empty()) {
      continue;
    }

    cout << "Query: " << query << "\n";

    auto movieIt = movieToActors.find(query);
    if (movieIt != movieToActors.end()) {
      // Query is a movie: print all actors in that movie.
      for (const string &actor : movieIt->second) {
        cout << actor << "\n";
      }
    } else {
      auto actorIt = actorToMovies.find(query);
      if (actorIt != actorToMovies.end()) {
        // Query is an actor: print all movies for that actor.
        for (const string &movie : actorIt->second) {
          cout << movie << "\n";
        }
      } else {
        cout << "Not Found\n";
      }
    }

    cout << "-----\n";
  }

  const auto searchEnd = chrono::high_resolution_clock::now();
  queryFile.close();

  const auto createTimeUs =
      chrono::duration_cast<chrono::microseconds>(createEnd - createStart)
          .count();
  const auto searchTimeUs =
      chrono::duration_cast<chrono::microseconds>(searchEnd - searchStart)
          .count();
  const auto totalTimeUs = createTimeUs + searchTimeUs;

  cout << fixed << setprecision(3);
  cout << "\n=== Performance Metrics ===\n";
  cout << "DB file: " << dbFileName << "\n";
  cout << "# of records: " << recordCount << "\n";
  cout << "Time to create data structure: " << (createTimeUs / 1000.0)
       << " ms\n";
  cout << "Time to search/retrieve: " << (searchTimeUs / 1000.0) << " ms\n";
  cout << "Total time: " << (totalTimeUs / 1000.0) << " ms\n";

  return 0;
}
