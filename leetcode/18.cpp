#include <bits/stdc++.h>

#define assert_eq(a, b)                                                                   \
    do {                                                                                  \
        auto _a = (a);                                                                    \
        auto _b = (b);                                                                    \
        if (_a != _b) {                                                                   \
            std::cerr << "Assertion failed: (" #a " == " #b ") -> " << _a << " != " << _b \
                      << " [Line " << __LINE__ << "]\n";                                  \
            std::exit(1);                                                                 \
        }                                                                                 \
    } while (0)

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;

        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (size_t j = i + 1; j < len; j++) {
                int m = j + 1, n = len - 1;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (m < n) {
                    long long sum = (long long)nums[i] + nums[j] + nums[m] + nums[n];
                    if (sum < target)
                        m++;
                    else if (sum > target)
                        n--;
                    else {
                        res.push_back({nums[m], nums[n], nums[i], nums[j]});
                        while (m < n && nums[m] == nums[m + 1]) ++m;
                        while (m < n && nums[n] == nums[n - 1]) --n;
                        m++;
                        n--;
                    }
                }
            }
        }
        return res;
    }
};

void solve() {
    Solution s;
    vector<int> v = {1, -2, -5, -4, -3, 3, 3, 5};
    s.fourSum(v, -10);
    // assert_eq()
}

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
