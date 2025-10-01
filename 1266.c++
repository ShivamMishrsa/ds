#include <bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int totalTime = 0;

    for (int i = 1; i < points.size(); i++) {
        int dx = abs(points[i][0] - points[i - 1][0]);
        int dy = abs(points[i][1] - points[i - 1][1]);
        totalTime += max(dx, dy);
    }

    return totalTime;
}

int main() {
    vector<vector<int>> points = {{1,1}, {3,4}, {-1,0}};
    cout << "Minimum time: " << minTimeToVisitAllPoints(points) << " seconds\n";
    return 0;
}
