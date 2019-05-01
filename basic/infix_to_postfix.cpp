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

bool isAlpha(char x) {
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
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

int precedence(char x) {
    if (x == '(' || x == '{' || x == '[') {
        return 3;
    } else if ( x == '*' || x == '/') {
        return 2;
    } else if ( x == '+' || x == '-') {
        return 1;
    }
    cout << "Invalid Operation" << endl;
    return -1;
}

bool isHigherPrecedence(char x, char y) {
    if (precedence(x) >= precedence(y))
        return true;
    return false;
}
string infix_to_postfix(string infix) {
    string postfix = "";
    stack<char> S;
    for(int i = 0; i < infix.size(); i++) {
        char current = infix.at(i);
        if (isDigit(current)) {
            postfix += current;
            postfix += " ";
        } else if (isOperator(current)) {
            while( !S.empty() && isHigherPrecedence(S.top(), current)) {
                postfix += S.top();
                postfix += " ";
                S.pop();
            }
            S.push(current); 
        }
    }
    while(!S.empty()) {
        postfix += S.top();
        postfix += " ";
        S.pop();
    }
    return postfix;
}

int evaluate_postfix(string text) {
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

int evaluate(string expression) {
    string postfix;
    postfix = infix_to_postfix(expression);
    return evaluate_postfix(postfix);
}
int main(void) {
    string text;
    getline(cin, text);
    // cin >> text;
    cout << evaluate(text) << endl;
    // cout << infix_to_postfix(text) << endl;
    return 0;
}