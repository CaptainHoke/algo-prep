#include <bits/stdc++.h>

long long largestPerimeter(std::vector<int>& nums) {
    std::ranges::sort(nums);
    long long result = std::accumulate(nums.begin(), nums.end(), 0ll);
    int largestSideIndex = static_cast<int>(nums.size()) - 1;

    while (largestSideIndex > 1 && result - nums[largestSideIndex] <= nums[largestSideIndex]) {
        result -= nums[largestSideIndex];
        largestSideIndex--;
    }

    return largestSideIndex > 1 ? result : -1;
}

int main() {

    return 0;
}
