#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    int n = nums.size();

    // Mark visited indices by negating the number at that index
    for (int i = 0; i < n; ++i) {
        int index = std::abs(nums[i]) - 1;  // Convert value to index
        if (nums[index] > 0) {
            nums[index] = -nums[index];     // Mark as visited
        }
    }

    // Now, the indices with positive values are missing numbers
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            result.push_back(i + 1);        // Because index starts from 0
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> missing = findDisappearedNumbers(nums);

    std::cout << "Missing numbers: ";
    for (int num : missing) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
