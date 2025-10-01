#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0; // A mountain must have at least 3 elements

    int maxLen = 0; 
    int i = 1; // Start from the second element (first possible peak position)

    while (i < n - 1) { // Stop before the last element (cannot be a peak)
        // Check if arr[i] is a peak
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int left = i;   // Left pointer starting from peak
            int right = i;  // Right pointer starting from peak

            // Move left pointer backwards while sequence is strictly increasing
            while (left > 0 && arr[left] > arr[left - 1]) {
                left--;
            }

            // Move right pointer forwards while sequence is strictly decreasing
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // Calculate current mountain length
            int currentLen = right - left + 1;
            maxLen = max(maxLen, currentLen); // Update maximum length

            // Move i to the end of current mountain to skip re-checking
            i = right;
        } else {
            i++; // Move to next element if not a peak
        }
    }

    return maxLen; // Return the longest mountain length found
}

int main() {
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    cout << "Length of longest mountain: " << longestMountain(arr) << endl;
    return 0;
}
