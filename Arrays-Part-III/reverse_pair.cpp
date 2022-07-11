#include <bits/stdc++.h>
using namespace std;

// guide https://takeuforward.org/data-structure/count-reverse-pairs/
int merging(vector<int> &arr, int low, int mid, int high)
{

    int j = mid, count_inv = 0;
    for (int i = low; i < mid; i++)
    {
        while (j <= high && arr[i] > 2 * arr[j])
        {
            j++;
        }
        count_inv += (j - mid);
    }

    int i = low;
    j = mid;
    int k = 0, n = high - low + 1;
    vector<int> temp(n);

    while (i < mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int y = 0; y < n; y++)
    {
        arr[low++] = temp[y];
    }
    return count_inv;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int mid = 0, count = 0;
    if (low < high)
    {
        mid = low + (high - low) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merging(arr, low, mid + 1, high);
    }

    return count;
}
int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{

    vector<int> arr = {1, 2, 3, 2, 3, 1};
    cout << reversePairs(arr, 6);
}