#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool check_balanced_paranthesis(string text) {
    stack<char> S;
    map<char, char> brackets;
    brackets.insert ( pair<char, char>('}', '{') );
    brackets.insert ( pair<char, char>(']', '[') );
    brackets.insert ( pair<char, char>(')', '(') );
    char current;
    for(int i=0; i<text.size(); i++) {
        current = text.at(i);
        if(current == '{' || current == '[' || current == '(') {
            S.push(current);
        }
        else if (current == '}' || current == ']' || current == ')') {
            if (S.empty()) {
                return false;
            }
            char topOfStack = S.top();
            if (topOfStack == brackets.find(current)->second) {
                S.pop();
            } else {
                return false;
            }
        }
    }
    return S.empty()? true: false;
}
int main(void) {
    string text;
    cin >> text;
    cout << check_balanced_paranthesis(text) << endl;
    return 0;
}