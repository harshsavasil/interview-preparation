/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 
*/
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main () {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arrive, depart;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arrive.push_back(num);
        }
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            depart.push_back(num);
        }
        sort(arrive.begin(), arrive.end());        
        sort(depart.begin(), depart.end());
        int i = 0, j = 0;
        int maxRooms = 0, numOfRoomsRequired = 0;
        while(i < n && j < n) {
            if (arrive[i] < depart[j]) {
                i++;
                numOfRoomsRequired++;
                maxRooms = max(numOfRoomsRequired, maxRooms);
            } else {
                j++;
                numOfRoomsRequired--;
            }
        }
        cout << "Minimum number of rooms required : " << maxRooms << endl;
    }
    return 0;
}
