#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    return false;
}

bool isDigit(char x) {
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

int performOperation(char operation, int operand1, int operand2) {
    if (operation == '+') { return operand1 + operand2;}
    else if (operation == '-') { return operand1 - operand2;}
    else if (operation == '*') { return operand1 * operand2;}
    else if (operation == '/') { return operand1 / operand2;}
    cout << " Invalid Operation " << endl;
    return -1;
}
void displayStack(stack<int> S) {
    while(!S.empty()) {
        cout << S.top() << ", ";
        S.pop();
    }
    cout << endl;
}

int evaluate(string text) {
    stack<int> S;
    char current;
    for(int i=0; i < text.size(); i++) {
        current = text.at(i);
        if (current == ' ' || current == ',') continue;
        else if (isOperator(current)) {
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            int result = performOperation(current, operand1, operand2);
            S.push(result);
        } else if (isDigit(current)) {
            int operand = 0;
            while( i < text.size() && isDigit(text.at(i))) {
                operand = (operand * 10) + (text.at(i) - '0');
                i++;
            }
            i--;
            S.push(operand);
        }
        // displayStack(S);
    }
    // displayStack(S);
    // cout << S.top() << endl;
    return S.top();
}

int main(void) {
    string text;
    // stringstream ss;
    getline(cin, text);
    // cin >> text;
    cout << evaluate(text) << endl;
    return 0;
}