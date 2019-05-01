#include <bits/stdc++.h>
#define ALPHA_MAX 62

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

// 0-9 (0-9) A-Z (10-35) a-z(36-61)

struct trieNode {
    vector<trieNode*> children;
    bool is_leaf;
};

class Trie {
    private:
        trieNode *rootNode;
        int getCharacterMapping(int characterValue) {
            // cout<<"c: "<<characterValue<<endl;
            if (characterValue >= 48 && characterValue<= 57) {
                return characterValue - 48;
            }
            else if (characterValue >= 65 && characterValue <= 90) 
                return characterValue - 65 + 10;
            else if (characterValue >= 97 && characterValue <= 122)
                return characterValue - 97 + 36;
            else 
                return -1;
                // unsupported characters
        }
        char getReverseCharacterMapping(int x) {
            if (x >= 0 && x<= 9) {
                // cout<<"x: "<<char(x+48)<<endl;
                return char(x + 48);
            }
            else if (x >= 10 && x <= 35) 
                return char(x + 65 - 10);
            else if (x >= 36 && x <= 61)
                return char(x + 97 - 36);
            else 
                return '\0';
                // unsupported characters
        }
        bool isLeafNode(trieNode *node) {
            return node->is_leaf;
        }
    public:
        Trie() {
            rootNode->children.assign(ALPHA_MAX, NULL);
            rootNode->is_leaf = false;
        }
        trieNode* getRoot() {
            return rootNode;
        }
        void createTrie(const vector<string> &x) {
            trieNode *currentNode = new trieNode;
            for(int i = 0; i < x.size(); i++) {
                currentNode = rootNode;
                string pattern = x[i];
                for(int j=0; j < pattern.size(); j++) {
                    int characterMapping = getCharacterMapping(int(pattern[j]));
                    if (currentNode->children.at(characterMapping) != NULL) {
                        currentNode = currentNode->children.at(characterMapping);
                    } else {
                        trieNode *newNode = new trieNode;
                        newNode->children.assign(ALPHA_MAX, NULL);
                        newNode->is_leaf = false;
                        currentNode->children.at(characterMapping) = newNode;
                        currentNode = newNode;
                    }
                }
                currentNode->is_leaf = true;
            }
        }

        // function to display the content of Trie 
        void display(trieNode *currentNode, string str, int level) {
            if (isLeafNode(currentNode)) { 
                str.at(level) = '\0'; 
                cout << str << endl; 
            }  
            for (int i = 0; i < ALPHA_MAX; i++) {  
                if (currentNode->children[i] != NULL) {
                    cout<<i<<endl;
                    str.at(level) = getReverseCharacterMapping(i); 
                    display(currentNode->children[i], str, level + 1); 
                } 
            } 
        } 
};

int main() {
    Trie dictonary;
    int n;
    string word;
    cin>>n;
    vector<string> words;
    while(n--) {
        cin>>word;
        words.push_back(word);
    }
    dictonary.createTrie(words);
    string str;
    str.assign(20, '\0');
    dictonary.display(dictonary.getRoot(), str, 0);
    return 0;
}