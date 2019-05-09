// TC - O(n) | SC- O(n)
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vi arr;
    vi rightMax(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    // we can assign -1 because the array must contain non-negative values in this case.
    int rightMaxElement = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        rightMax[i] = rightMaxElement;
        if (arr[i] > rightMaxElement)
        {
            rightMaxElement = arr[i];
        }
    }
    int leftMax = arr[0];
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        result += min(leftMax, rightMax[i]) - arr[i] > 0 ? min(leftMax, rightMax[i]) - arr[i] : 0;
        if (leftMax < arr[i])
            leftMax = arr[i];
    }
    cout << "Total Water Trapped using precomputation: " << result << endl;
    return 0;
}