#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) {
            return true; // Duplicate found
        }
        seen.insert(num);
    }
    return false; // All elements are unique
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 1};

    if (containsDuplicate(nums)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
