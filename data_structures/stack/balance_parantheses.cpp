#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0
typedef vector<int> vi;

void display(stack<char> S) {
	while(!S.empty()) {
		cout << S.top() << ", ";
		S.pop();
	}
	cout << endl;
}

int main() {
 	string text;
 	cin >> text;
 	stack<char> S;
 	string unbalanced = "";
 	for(int i = 0; i < text.size(); i++) {
 		// cout << text[i] << endl;
 		if(text[i] == '{') {
 			S.push(text[i]);
 		} else {
 			if (!S.empty() && S.top() == '{') {
 				S.pop();
 			}
 			else {
 				S.push(text[i]);
 			}
 		}
 	}
 	while(!S.empty()) {
        unbalanced += S.top();
        S.pop();
    }
    reverse(unbalanced.begin(), unbalanced.end());
    cout << unbalanced << endl;
 	return 0;

 }