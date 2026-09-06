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
    int myAtoi(string s) {
        int index = 0, sign = 1;
        while (s[index] == ' ') index++;
        if (index > s.size()) return 0;

        if (s[index] == '+' || s[index] == '-') {
            sign *= 44 - (int)s[index];
            index++;
        }

        int max = 2147483647;
        long res = 0;

        while ('0' <= s[index] && s[index] <= '9') {
            res *= 10;
            if (res > max) return (sign == -1 ? -max + sign : max);
            res = res + s[index] - '0';
            index++;
        }
        if (res > max) return (sign == -1 ? -max + sign : max);
        return res * sign;
    }
};

void solve() {
    Solution s;
    assert_eq(s.myAtoi("2147483648"), 2147483647);
    assert_eq(s.myAtoi(""), 0);
    assert_eq(s.myAtoi("                "), 0);
    assert_eq(s.myAtoi("42"), 42);
    assert_eq(s.myAtoi("   -042"), -42);
    assert_eq(s.myAtoi("1337c0d3"), 1337);
    assert_eq(s.myAtoi("0-1"), 0);
    assert_eq(s.myAtoi("words and 987"), 0);
    // assert_eq()
}

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
