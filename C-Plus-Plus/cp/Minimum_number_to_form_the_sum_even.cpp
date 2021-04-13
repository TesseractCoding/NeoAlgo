/*
Description : Given an array and size, the task is to add the minimum number
              (should be greater than 0) to the array so that the sum of the 
              array becomes even .
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNum(long long int arr[], int n)
    {
        long sum = 0;
        sum = accumulate(arr, arr + n, sum);
        if (sum == 0)
        {
            return 0;
        }
        else if (sum % 2 == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    long long a[n];
    cout << "Enter " << n << " number of elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Solution obj;
    cout << "Minimum Number to be added in the array : " << endl;
    cout << obj.minNum(a, n);

    return 0;
}

/*
Time complexity : O(n)
Space complexity : On)
*/

/*
Test Cases : 
Test Case 1 : 
    Input :
    Enter the size of the array : 
    8
    Enter 8 number of elements : 
    1 2 3 4 5 6 7 8

    Output :
    Minimum Number to be added in the array : 
    2
Test Case 2 :
    Input :
    Enter the size of the array : 
    9
    Enter 9 number of elements : 
    1 2 3 4 5 6 7 8 9

    Output :
    Minimum Number to be added in the array : 
    1
*/

