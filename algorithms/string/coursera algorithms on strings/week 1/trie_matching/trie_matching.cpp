#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

typedef vector<Node*> trie;

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

trie createTrie(const vector<string> &x) {
	trie patternsTrie;
	Node *root = new Node;
	patternsTrie.push_back(root);
	Node *currentNode = new Node;
	for(int i = 0; i < x.size(); i++) {
		currentNode = patternsTrie.at(0);
		string pattern = x[i];
		for(int j=0; j < pattern.size(); j++) {
			int characterMapping = letterToIndex(pattern[j]);
			if (currentNode->next[characterMapping] != NA) {
				currentNode = patternsTrie.at(currentNode->next[characterMapping]);
			} else {
				Node *newNode = new Node;
				currentNode->next[characterMapping] = patternsTrie.size();
				currentNode = newNode;
				patternsTrie.push_back(currentNode);
			}
		}
	}
	return patternsTrie;
}

bool prefixTrieMatching(string text, trie patternsTrie) {
	int currentSymbol = 0;
	Node *currentNode = patternsTrie[0];
	while(true) {
		// cout << "index: " << currentSymbol << "text " << text << " " << currentNode->isLeaf() << endl;
		// cout << currentNode->next[0] << currentNode->next[1] << currentNode->next[2] << endl;
		if(currentNode->isLeaf()) {
			return true;
		}
		else if(currentSymbol < text.size() && currentNode->next[letterToIndex(text[currentSymbol])] != NA) {
			currentNode = patternsTrie.at(currentNode->next[letterToIndex(text[currentSymbol])]);
			currentSymbol += 1; 
		}
		
		else {
			return false;
		}
	}
}
vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	trie patternsTrie = createTrie(patterns);
	for(int i=0; i < text.size(); i++) {
		if (prefixTrieMatching(text.substr(i), patternsTrie)) {
			// cout << "index: " << i << endl;
			result.push_back(i);
		}
	}
	return result;
}

int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
