#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

bool sortValues(ii a, ii b) {
    return a.first < b.first;
}

int main () {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int n1 = n;
        vector<int> arrive, depart;
        while(n--) {
            int num;
            cin >> num;
            arrive.push_back(num);
        }
        while(n1--) {
            int num;
            cin >> num;
            depart.push_back(num);
        }
        vector<ii> bookings;
        for(int i = 0; i < arrive.size(); i++) {
            bookings.push_back(make_pair(arrive[i], depart[i]));
        }
        sort(bookings.begin(), bookings.end());
        int maxRooms = 1, numOfRoomsRequired = 1;
        // ii currentLimit = bookings[0];
        for(int i = 1; i < bookings.size(); i++) {
            if (bookings[i].first < bookings[i-1].second) {
                numOfRoomsRequired++;
                maxRooms = max(numOfRoomsRequired, maxRooms);
            } else {
                numOfRoomsRequired--;
            }
        }
        for(int i = 0; i < bookings.size(); i++) {
            cout << i+1 << " : " << bookings[i].first << " : " << bookings[i].second << endl;
        }
        cout << maxRooms << endl;
    }
    return 0;
}
