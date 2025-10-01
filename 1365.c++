#include <iostream>
#include <vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> count(101, 0); // since 0 <= nums[i] <= 100

    // Step 1: Count frequency of each number
    for (int num : nums) {
        count[num]++;
    }

    // Step 2: Prefix sum to find how many numbers are smaller
    for (int i = 1; i <= 100; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Build result
    vector<int> result;
    for (int num : nums) {
        if (num == 0) result.push_back(0);
        else result.push_back(count[num - 1]);
    }

    return result;
}

int main() {
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> ans = smallerNumbersThanCurrent(nums);

    for (int num : ans) cout << num << " ";
    return 0;
}
