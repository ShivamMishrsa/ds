#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());
    int n = arr.size();
    
    int minDiff = INT_MAX;
    vector<vector<int>> result;
    
    // Step 2: Slide a window of size 2
    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i+1] - arr[i];  // window of two elements
        
        if (diff < minDiff) {
            // Found smaller difference → reset result
            minDiff = diff;
            result.clear();
            result.push_back({arr[i], arr[i+1]});
        }
        else if (diff == minDiff) {
            // Same as current minimum → add pair
            result.push_back({arr[i], arr[i+1]});
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {4, 2, 1, 3};
    vector<vector<int>> ans = minimumAbsDifference(arr);
    
    cout << "Pairs with minimum absolute difference:\n";
    for (auto &p : ans) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }
    return 0;
}
