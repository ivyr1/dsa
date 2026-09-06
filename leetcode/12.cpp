#include <bits/stdc++.h>

#include <cstdint>
#include <vector>

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
    vector<pair<int, string>> v = {
        {1, "I"},   {4, "IV"},  {5, "V"},    {9, "IX"},  {10, "X"},   {40, "XL"},  {50, "L"},
        {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"},
    };
    string intToRoman(int num) {
        // code
        string res = "";
        int8_t i = 12;
        while (num > 0) {
            if (num >= v[i].first) {
                res += v[i].second;
                num -= v[i].first;
            } else {
                i--;
                if (i < 0) break;
            }
        }
        return res;
    }
};

void solve() {
    Solution s;
    assert_eq(s.intToRoman(3749), "MMMDCCXLIX");
    assert_eq(s.intToRoman(58), "LVIII");
    // assert_eq()
}

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
