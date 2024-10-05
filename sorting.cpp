#include <iostream>
using namespace std;
void selection_sort(int arr[],int n)        // time copmplexity O(n^2)  find smallest element and replace with current element.
{
    for(int i=0;i<=n-2;i++)
    {
        int min = i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void bubble_sort(int arr[],int n)   // time complexity == O(n^2) if the given arr is sorted so ttime complexity O(n) compare adjacent two elements
{   int temp ;
    int didswap = 0;
    for(int i = n-1;i>=1;i--)
    {
        for(int j = 0;j<=i;j++)
        {
            if( arr[j] > arr[j+1])
            {
               temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            return;
        }
        cout<<"run\n";
    }
}
void insertion_sort(int arr[],int n)    // time complexity == O(n^2) if the given arr is sorted so ttime complexity O(n)  put element in correct order by comparing with left element
{
    for(int i = 0;i<=n-1;i++)
    {
        int j = i,temp;
        while(j>0 && arr[j-1]>arr[j])
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter length of array:- ";
    cin>>n;
    int arr[n];
    cout<<"Enter arr elements\n";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    insertion_sort(arr,n);
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}