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
    int maxArea(vector<int>& height) {
        // code
        int len = (int)height.size();
        int maxA = -1;

        int i = 0, j = len - 1;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            maxA = max(maxA, area);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }

        return maxA;
    }
};

void solve() {
    Solution s;
    vector<int> v1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // {1, 2, 3, 4, 5, 6, 7, 8, 8}
    vector<int> v2 = {1, 1};
    vector<int> v3 = {1, 0, 0, 0, 0, 0, 0, 2, 2};
    assert_eq(s.maxArea(v1), 49);
    assert_eq(s.maxArea(v2), 1);
    assert_eq(s.maxArea(v3), 8);
    // assert_eq()
}

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
