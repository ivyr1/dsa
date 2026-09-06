#include <bits/stdc++.h>

#include <cassert>
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
    int lengthOfLongestSubstring(string s) {
        int m[128];
        memset(m, -1, sizeof(m));

        int record = 0;
        int cur = 0;
        int start = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (m[s[i] - 'a'] == -1 || m[s[i] - 'a'] < start) {
                cur++;
            } else {
                int k = m[s[i] - 'a'];
                record = max(record, cur);
                cur = i - k;
                start = k + 1;
            }
            m[s[i] - 'a'] = i;
        }
        record = max(record, cur);

        return record;
    }
};

void solve() {
    Solution s;
    assert_eq(s.lengthOfLongestSubstring("abcabcbb"), 3);
    assert_eq(s.lengthOfLongestSubstring("bbbbb"), 1);
    assert_eq(s.lengthOfLongestSubstring("pwwkew"), 3);
}

int main() {
    solve();
    return 0;
}
