#include <bits/stdc++.h> 
using namespace std;
long long merge(long long *arr,long long *temp,int low ,int mid, int high)
{
    long long count_inv = 0;
    int i = low , j = mid, k = low;
    while((i < mid) && (j <= high))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count_inv  = count_inv + (mid-i);
        }
    }
    
    while(i < mid)
    {
        temp[k++] = arr[i++];
       
    }
    while(j <= high)
       temp[k++] = arr[j++];
    
    while(low <= high)
    {
        arr[low] = temp[low++];
    }
    return count_inv;
}
long long _mergesort(long long *arr,long long *temp,int low , int high)
{
    long long count = 0,mid;
    if(low < high)
    {
         mid = (low + high)/2;
       count +=  _mergesort(arr,temp,low,mid);
      count +=   _mergesort(arr,temp,mid+1,high);
      count +=   merge(arr,temp,low,mid+1 , high);
    }
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your  code here.
    long long *temp = new long long[n];
    return _mergesort(arr,temp,0,n-1);
}