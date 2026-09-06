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
    vector<vector<int>> threeSum(vector<int>& nums) {
        // code
        sort(nums.begin(), nums.end());
        size_t len = nums.size();

        vector<vector<int>> res;

        for (size_t i = 0; i < len; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int m = i + 1, n = len - 1;
            while (m < n) {
                if (nums[m] + nums[n] < -nums[i])
                    m++;
                else if (nums[m] + nums[n] > -nums[i])
                    n--;
                else {
                    res.push_back({nums[m], nums[n], nums[i]});
                    while (m < n && nums[m] == nums[m + 1]) ++m;
                    while (m < n && nums[n] == nums[n - 1]) --n;
                    m++;
                    n--;
                }
            }
        }
        return res;
    }
};

void solve() { Solution s; }

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
