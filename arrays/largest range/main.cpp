/*
Largest Range
Find the biggest range of consecutive numbers in an array.

Sample Input: [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6]
Sample Output: [0, 7]
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> getLargestRange(vector<int> array) {
	int n = array.size();
	unordered_map<int, bool> present;
	for(int i = 0; i < n; i++) {
		present[array[i]] = false;
	}
	int maxLength = 0;
	int currentLength;
	int start, end;
	for(int i = 0; i < n; i++) {
		if (!present[array[i]]) {
			present[array[i]] = true;
			int next = array[i] + 1;
			int prev = array[i];
			currentLength = 0;
			while(present.find(prev) != present.end()) {
				currentLength += 1;
				present[prev] = true;
				prev--;
			}
			while(present.find(next) != present.end()) {
				currentLength += 1;
				present[next] = true;
				next++;
			}
			if(currentLength > maxLength) {
				maxLength = currentLength;
				start = prev + 1;
				end = next - 1;
			}
		}
	}
	return vector<int>({start, end});
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> array;
	while(n--) {
		int num;
		cin >> num;
		array.push_back(num);
	}
	vector<int> largestRange = getLargestRange(array);
	cout << "Start: " << largestRange[0] << " End: " << largestRange[1] << endl;
    return 0;
}