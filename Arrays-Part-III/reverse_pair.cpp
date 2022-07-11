#include <bits/stdc++.h> 
using namespace std;
int merging(vector<int> &arr,int low, int mid, int high)
{
    int i = low , j = mid, k = 0,n = high-low+1 , count = 0;
    vector<int> temp(n);
    
    while(i < mid && j <= high)
    {
        if(arr[i] > 2*arr[j])
        {
            temp[k++] = arr[j];
            count += (mid-i);
            j++;
        }
        else if(arr[i] > arr[j])
        {
            temp[k++] = arr[j];
            j++;
        }
        else
        {
            temp[k++] = arr[i];
            i++;
        }
    }
    
    while(i < mid)
    {
        temp[k++] = arr[i];
            i++;
    }
    
    while(j <= high)
    {
        temp[k++] = arr[j];
            j++;
    }
    
    for(int y = 0;y<n;y++)
    {
        arr[low++] = temp[y];
    }
    return count;
}







int mergeSort(vector<int> &arr,int low, int high)
{
    int mid = 0, count = 0;
    while(low < high)
    {
        mid = low+(high-low)/2;
      count +=  mergeSort(arr,low,mid);
      count +=   mergeSort(arr,mid+1,high);
     count += merging(arr,low,mid+1,high);
    }
    
    return count;
}
int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr,0,n-1);
}


int main()
{

    vector<int> arr = {1, 2, 3, 2, 3, 1};
    cout << reversePairs(arr,6);
}