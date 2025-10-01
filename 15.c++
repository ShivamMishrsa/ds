#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    
    // Step 1: Sort the array to use two-pointer technique and handle duplicates easily
    sort(nums.begin(), nums.end());
    int n = nums.size();

    // Step 2: Loop through each number as the first element of the triplet
    for (int i = 0; i < n; i++) {

        // Skip duplicate elements for the first number to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Step 3: Use two pointers for the remaining two numbers
        int left = i + 1;       // Start just after i
        int right = n - 1;      // Start from the last element

        // Step 4: Move the pointers towards each other
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // Found a valid triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for 'left'
                while (left < right && nums[left] == nums[left + 1]) left++;
                // Skip duplicates for 'right'
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move both pointers after processing
                left++;
                right--;
            }
            else if (sum < 0) {
                // If sum is too small, move left pointer to increase sum
                left++;
            }
            else {
                // If sum is too large, move right pointer to decrease sum
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Call the function
    vector<vector<int>> ans = threeSum(nums);

    // Print the result
    for (auto &triplet : ans) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    return 0;
}
