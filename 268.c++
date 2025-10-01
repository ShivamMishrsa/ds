#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();  // Size is n, numbers are in range [0, n]
    int total = n * (n + 1) / 2;

    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    return total - sum;  // The missing number
}

int main() {
    std::vector<int> nums = { 3, 0, 1, };  // Example input
    int missing = missingNumber(nums);
    std::cout << "Missing number is: " << missing << std::endl;
    return 0;
}
