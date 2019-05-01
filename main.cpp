#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cmath>

#define pb push_back
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

struct compareValues {
    bool operator()(const ii& a, const ii& b) {
        return a.first < b.first;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(true) {
        int noOfCities, ballotBoxes;
        scanf("%d %d", &noOfCities, &ballotBoxes);
        if (noOfCities == -1 && ballotBoxes == -1) break;
        priority_queue<ii, vector<ii>, compareValues> maxPeoplePerBallot;
        vi population;
        // at least 1 box must be given to every city. 
        // If this condition is not satisfied. No possible Solution.
        int value;
        for(int index = 0; index < noOfCities; index++) {
            scanf("%d", &value);
            population.push_back(value);
            maxPeoplePerBallot.push(make_pair(value, index));
        }
        vi ballotDistribution(noOfCities, 1);
        // every city is supposed to have atleast one ballot
        ballotBoxes = ballotBoxes - noOfCities;
        while(ballotBoxes > 0) {
            ii currentMax = maxPeoplePerBallot.top();
            maxPeoplePerBallot.pop();
            ballotDistribution[currentMax.second]++;
            int newMax = ceil((population[currentMax.second] * 1.0) / ballotDistribution[currentMax.second]);
            maxPeoplePerBallot.push(make_pair(newMax, currentMax.second));
            ballotBoxes--;
        }
        printf("%d\n", maxPeoplePerBallot.top().first);
    }
    return 0;
}