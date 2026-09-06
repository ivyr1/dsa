#include <bits/stdc++.h>

#include <cassert>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string res = "";
        sort(s.begin(), s.end());

        return res;
    }
};

void solve() {
    Solution s;
    cout << s.lexGreaterPermutation("abc", "bba") << endl;
    assert(s.lexGreaterPermutation("abc", "bba") == "bca");

    cout << s.lexGreaterPermutation("leet", "code") << endl;
    assert(s.lexGreaterPermutation("leet", "code") == "eelt");

    cout << s.lexGreaterPermutation("abc", "abc") << endl;
    assert(s.lexGreaterPermutation("abc", "abc") == "bac");

    cout << s.lexGreaterPermutation("aba", "abb") << endl;
    assert(s.lexGreaterPermutation("aba", "abb") == "baa");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
