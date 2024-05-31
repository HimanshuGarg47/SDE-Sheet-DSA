
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {1, 3, 4, 5, 0, 2, 5};
    int max = arr[0];
    int sec = -1;
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sec && arr[i] != max)
        {
            sec = arr[i];
        }
    }
    cout << sec << endl;

    return 0;
}