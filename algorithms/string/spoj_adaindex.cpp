#include <bits/stdc++.h>
#define ALPHA_MAX 26

using namespace std; 

// a-z(0-25)

struct trieNode {
    vector<trieNode *> children;
    int occurence;
};


trieNode* createTrie() {
    trieNode *root = new trieNode;
    root->children.assign(ALPHA_MAX, NULL);
    root->occurence = 0;
    return root;
}

void addWord(trieNode *root, string pattern) {
    trieNode *currentNode = new trieNode;
    currentNode = root;
    for(int j=0; j < pattern.size(); j++) {
        int characterMapping = pattern[j] - 'a';
        if (currentNode->children.at(characterMapping) != NULL) {
            currentNode = currentNode->children.at(characterMapping);
            currentNode->occurence += 1;
        } else {
            trieNode *newNode = new trieNode;
            newNode->children.assign(ALPHA_MAX, NULL);
            newNode->occurence = 1;
            currentNode->children.at(characterMapping) = newNode;
            currentNode = newNode;
        }
    }
}
int countPrefixOccurences(trieNode *rootNode, string pattern) {
    trieNode *currentNode = new trieNode;
    currentNode = rootNode;
    int index = 0;
    int length = pattern.size();
    while(index < length) {
        // cout << pattern[index] << " " << currentNode->occurence << endl;
        if (currentNode->children[pattern[index] - 'a'] != NULL) {
            currentNode = currentNode->children[pattern[index] - 'a'];
        } else {
            return 0;
        }
        index += 1;
    }
    return currentNode->occurence;
}

int main() {
    trieNode *root;
    root = createTrie();
    int n, q;
    cin>>n>>q;
    string word;
    while(n--) {
        cin>>word;
        addWord(root, word);
    }
    while(q--) {
        cin>>word;
        cout << countPrefixOccurences(root, word) << endl;
    }
    return 0;
}