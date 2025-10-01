#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // ✅ Needed for INT_MAX

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Initially set to a very high value
    int maxProfit = 0;       // Initially no profit

    for (int price : prices) {
        minPrice = min(minPrice, price);               // Update min price so far
        maxProfit = max(maxProfit, price - minPrice);  // Update max profit
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}

