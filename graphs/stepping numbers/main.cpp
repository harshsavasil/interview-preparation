#include <iostream>
#include <queue>

using namespace std;

void printSteppingNumbers(int number, int n, int m) {
    queue<int> steps;
    steps.push(number);
    while(!steps.empty()) {
        int currentNumber = steps.front();
        steps.pop();
        int lastDigit = currentNumber % 10;
        if (currentNumber >=n && currentNumber <= m)
            cout << currentNumber << " ";
        if (currentNumber == 0 || currentNumber > m)
            continue;
        if (lastDigit == 0) {
            steps.push(currentNumber * 10 + (lastDigit + 1));
        } else if (lastDigit == 9) {
            steps.push(currentNumber * 10 + (lastDigit - 1));
        } else {
            steps.push(currentNumber * 10 + (lastDigit - 1));
            steps.push(currentNumber * 10 + (lastDigit + 1));
        }
    }
}
int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m, counter = 0;
    while(cin >> n >> m) {
        counter++;
        cout << "TEST CASE: " << counter << endl;
        for(int i = 0; i <= 9; i++) {
            printSteppingNumbers(i, n, m);
        }
        cout << endl;
    }
    return 0;
}