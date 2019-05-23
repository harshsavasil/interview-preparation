#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

void display(const vvi data)
{
    int row = data.size();
    int column = data[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int maxCapacity, n;
    cin >> n >> maxCapacity;
    vector<ii> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items.at(i).first >> items.at(i).second;
    }
    vvi maxCost(n, vi(maxCapacity + 1, 0));
    for (int i = 1; i <= maxCapacity; i++)
    {
        if (items[0].first <= i)
        {
            maxCost[0][i] = items[0].second;
        }
    }
    // display(maxCost);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= maxCapacity; j++)
        {
            // check if the item can be filled or not
            if (j >= items[i].first)
            {
                maxCost[i][j] = max(items[i].second + maxCost[i - 1][j - items[i].first], maxCost[i - 1][j]);
            }
            else
            {
                maxCost[i][j] = maxCost[i - 1][j];
            }
        }
    }
    display(maxCost);
    cout << maxCost[n - 1][maxCapacity] << endl;
    return 0;
}