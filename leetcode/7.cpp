#include <bits/stdc++.h>

#include <string>

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
    int reverse(int x) {
        // code
        if (x == 0) return 0;
        const string max = "2147483647";

        if (x == -2147483648) return 0;
        int k = abs(x);

        string xstr = to_string(x);

        std::reverse(xstr.begin(), xstr.end());
        if (x < 0 && xstr[xstr.size() - 1] != 0) xstr[xstr.size() - 1]--;

        if (xstr > max && k / 1E9 > 1.0)
            return 0;
        else
            return stoi(xstr) * (x / k);
    }
};

void solve() {
    Solution s;
    assert_eq(s.reverse(123), 321);
    assert_eq(s.reverse(-123), -321);
    assert_eq(s.reverse(120), 21);
}

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
