/*
Name: Vedanta Somnathe
Email: vpsomnathe@crimson.ua.edu
Course Section: Spring 2026 CS 201 002
Homework #: 4
To Compile: g++ -Wall -std=c++20 GraphDemo.cpp
To Run: ./a.out input1.txt
        ./a.out input2.txt
*/

#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>

class Vertex {
public:
  bool visited;
  int distance;
  int previous;
  int finish;
  std::list<int> adj;
};

class Graph {
public:
  Graph(int V, int E, std::pair<int, int> *edges) {
    _V = V;
    _E = E;
    vertices = new Vertex[_V];
    for (int i = 0; i < _V; i++) {
      vertices[i].visited = false;
      vertices[i].distance = 65535; // Instead using INFINITY, you can use a
                                    // large int number to initialize your graph
      vertices[i].previous = -1;
    }
    for (int i = 0; i < _E; i++) {
      addEdge(edges[i].first, edges[i].second);
    }
  }

  virtual ~Graph() {
    for (int i = 0; i < _V; ++i) {
      auto adj = vertices[i].adj;
      adj.clear(); // clear list
    }

    delete[] vertices; // delete array of vertices
  }

  int V() { return _V; }

  int E() { return _E; }

  void addEdge(int u, int v) { vertices[u].adj.push_back(v); }

  std::list<int> getEdges(int u) { return vertices[u].adj; }

  int degree(int u) { return vertices[u].adj.size(); }

  void bfs(int s) {
    for (int i = 0; i < _V; ++i) {
      vertices[i].visited = false;
      vertices[i].distance = 65535;
      vertices[i].previous = -1;
    }

    vertices[s].visited = true;
    vertices[s].distance = 0;
    vertices[s].previous = -1;

    std::queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (const auto &v : vertices[u].adj) {
        if (!vertices[v].visited) {
          vertices[v].visited = true;
          vertices[v].distance = vertices[u].distance + 1;
          vertices[v].previous = u;
          q.push(v);
        }
      }
    }
  }

  void dfs() { dfs(0); }

  void dfs(int s) {
    time = 0;
    for (int i = 0; i < _V; ++i) {
      vertices[i].visited = false;
      vertices[i].previous = -1;
      vertices[i].distance = 65535;
      vertices[i].finish = 0;
    }

    dfs_visit(s);
  }

  void dfs_visit(int u) {
    ++time;
    vertices[u].distance = time;
    vertices[u].visited = true;

    for (const auto &v : vertices[u].adj) {
      if (!vertices[v].visited) {
        vertices[v].previous = u;
        dfs_visit(v);
      }
    }

    ++time;
    vertices[u].finish = time;
  }

  void print_path(int s, int v) {
    if (v == s)
      std::cout << s;
    else if (vertices[v].previous == -1)
      std::cout << "not connected";
    else {
      print_path(s, vertices[v].previous);
      std::cout << "->" << v;
    }
  }

  std::string toString() {
    std::stringbuf buffer;
    std::ostream os(&buffer);
    os << "Vertices = " << _V << ", Edges = " << _E << std::endl;
    for (int i = 0; i < _V; ++i) {
      os << i << "(" << degree(i) << "): ";
      for (const auto &l : vertices[i].adj)
        os << l << " ";
      os << std::endl;
    }

    return buffer.str();
  }

private:
  int _V; // no. of vertices
  int _E; // no. of edges
  int time;
  Vertex *vertices; // array of vertices
};

#endif
