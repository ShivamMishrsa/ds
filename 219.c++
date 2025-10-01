#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;  // sliding window
    
    for (int i = 0; i < nums.size(); i++) {
        if (window.find(nums[i]) != window.end())
            return true; // duplicate within k
        
        window.insert(nums[i]);
        
        // Keep window size <= k
        if (window.size() > k)
            window.erase(nums[i - k]);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;
    return 0;
}
