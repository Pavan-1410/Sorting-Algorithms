#include<iostream>
using namespace std;
// time complexity :- n log2(n) as we are dividing the arry    
// space complexity :- O(1) as we do not using any extra arr
int quicksort(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<= high-1)
        {
            i++;
        }
        while(arr[j]>=pivot && j>= low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void divide(int arr[],int low,int high)
{
    if(low < high)
    {
        int pivot_index = quicksort(arr,low,high);
        divide(arr,low,pivot_index-1);
        divide(arr,pivot_index+1,high);
    }
}
int main()
{
    int n,x;
    cout<<"Enter size of arr:-";
    cin>>n;
    int arr[n];
    cout<<"Enter arr elemants\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[i] = x;
    }
    for (int i=0;i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    divide(arr,0,n-1);
    cout<<"\nsorted arr is \n";
    for (int i=0;i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}