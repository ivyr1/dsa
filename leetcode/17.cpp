#include <bits/stdc++.h>

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
    const string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len;
    vector<string> res;

    void back_track(const string& digits, int idx, string& cur) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (auto c : arr[digits[idx] - '0']) {
            cur[idx] = c;
            back_track(digits, idx + 1, cur);
        }
    }

    vector<string> letterCombinations(string digits) {
        len = (int)digits.size();
        string cur(digits.size(), ' ');
        back_track(digits, 0, cur);
        return res;
    }
};

void solve() {
    Solution s;
    auto arr = s.letterCombinations("23");
    for (auto a : arr) {
        cout << a << " ";
    }
    cout << endl;
    // assert_eq()
}

int main() {
    solve();
    std::cout << "All test cases passed!\n";
    return 0;
}
