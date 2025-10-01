#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashMap; // number -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if complement exists in hashMap
        if (hashMap.find(complement) != hashMap.end()) {
            return {hashMap[complement], i}; // return both indices
        }

        // Store current number with its index
        hashMap[nums[i]] = i;
    }

    return {}; // No solution found (problem guarantees one exists)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << "Indices: " << result[0] << " and " << result[1] << endl;

    return 0;
}
