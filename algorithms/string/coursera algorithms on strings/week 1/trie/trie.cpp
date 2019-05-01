#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  int currentnodeLabel = 0;
  edges rootEdges;
  t.push_back(rootEdges);
  for(size_t i=0; i < patterns.size(); i++) {
    currentnodeLabel = 0;
    for(size_t j=0; j < patterns[i].size(); j++) {
      char16_t symbol = patterns[i][j];
      map<char, int>::iterator edge;
      edge = t.at(currentnodeLabel).find(symbol);
      if(edge != t.at(currentnodeLabel).end()) {
        currentnodeLabel = edge->second;
      } else {
        t.push_back(rootEdges);
        t.at(currentnodeLabel)[symbol] = t.size() - 1;
        currentnodeLabel = t.size() - 1;
      }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}