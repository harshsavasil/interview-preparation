#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// Complete the droppedRequests function below.
int droppedRequests(vector<int> requestTime)
{
    int n = requestTime.size();
    int dropCount = 0;
    map<long, long> requestCount;
    for (int i = 0; i < n; i++)
    {
        requestCount[requestTime[i]]++;
    }
    int lastTenSecondCount = 0, lastMinuteCount = 0;
    queue<int> lastTenSecond, lastMinute;
    for (auto current : requestCount)
    {
        if (lastTenSecond.empty())
        {
            lastTenSecond.push(current.first);
            lastTenSecondCount += current.second;
        }
        else
        {
            if (current.first - lastTenSecond.front() > 9)
            {
                lastTenSecondCount -= requestCount[lastTenSecond.front()];
                lastTenSecond.pop();
            }
            lastTenSecond.push(current.first);
            lastTenSecondCount += current.second;
        }
        if (lastMinute.empty())
        {
            lastMinute.push(current.first);
            lastMinuteCount += current.second;
        }
        else
        {
            if (current.first - lastTenSecond.front() > 59)
            {
                lastMinuteCount -= requestCount[lastMinute.front()];
                lastMinute.pop();
            }
            lastMinute.push(current.first);
            lastMinuteCount += current.second;
        }
        dropCount += ((current.second > 3) ? current.second - 3 : 0);
        dropCount += (lastTenSecondCount > 20 ? lastTenSecondCount - 20 : 0);
        dropCount += (lastMinuteCount > 60 ? lastMinuteCount - 60 : 0);
    }
    return dropCount;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << droppedRequests(arr) << endl;
    return 0;
}