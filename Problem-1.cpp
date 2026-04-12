#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//store result
struct Result {
    int sum;
    int start;
    int end;
};

//find crossing subarray
Result maxCrossing(vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;
    int maxLeft = mid;

    // Left side (mid → left)
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int maxRight = mid + 1;

    // Right side (mid+1 → right)
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    return {leftSum + rightSum, maxLeft, maxRight};
}

// Divide & Conquer function
Result maxSubarray(vector<int>& arr, int left, int right) {
    // Base case
    if (left == right) {
        return {arr[left], left, right};
    }

    int mid = (left + right) / 2;

    // Divide
    Result leftResult = maxSubarray(arr, left, mid);
    Result rightResult = maxSubarray(arr, mid + 1, right);
    Result crossResult = maxCrossing(arr, left, mid, right);

    // Conquer (choose best)
    if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossResult.sum)
        return leftResult;
    else if (rightResult.sum >= leftResult.sum && rightResult.sum >= crossResult.sum)
        return rightResult;
    else
        return crossResult;
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Result ans = maxSubarray(arr, 0, n - 1);

    cout << "\nMaximum Sum: " << ans.sum << endl;
    cout << "Start Index: " << ans.start << endl;
    cout << "End Index: " << ans.end << endl;

    return 0;
}
