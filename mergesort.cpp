#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];  // Temporary array to hold merged result
    int left = low;            // Left pointer to the first subarray
    int right = mid + 1;       // Right pointer to the second subarray
    int index = 0;             // Index for the temporary array

    // Merging the two subarrays
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[index++] = arr[left];
            left++;
        } else {
            temp[index++] = arr[right];
            right++;
        }
    }

    // Copy any remaining elements from the left subarray
    while (left <= mid) {
        temp[index++] = arr[left];
        left++;
    }

    // Copy any remaining elements from the right subarray
    while (right <= high) {
        temp[index++] = arr[right];
        right++;
    }

    // Copy the sorted elements back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void divide(int arr[], int low, int high) {
    if (low == high) {
        return;  // Base case: if the array has one or no elements
    }

    int mid = (low + high) / 2;  // Proper formula to find the middle index

    divide(arr, low, mid);     // Recursively divide the left half
    divide(arr, mid + 1, high);  // Recursively divide the right half

    merge(arr, low, mid, high);  // Merge the two halves
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n]; 
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform merge sort
    divide(arr, 0, n - 1);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
