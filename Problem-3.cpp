
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex < k)
            return quickSelect(arr, pivotIndex + 1, right, k);
        else
            return quickSelect(arr, left, pivotIndex - 1, k);
    }
    return -1;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int targetIndex = n - k;

    int result = quickSelect(arr, 0, n - 1, targetIndex);

    cout << "\nK-th Largest Element: " << result << endl;

    return 0;
}
