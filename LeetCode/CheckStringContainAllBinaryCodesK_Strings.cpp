// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
// Input: s = "00110110", k = 2
// Output: true

#include <iostream>
#include <unordered_set>
using namespace std;    

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        unordered_set<string> st;
        int total = 1 << k;
        for (int i = 0; i + k <= s.length(); i++) {
            st.insert(s.substr(i, k));
            if (st.size() == total)
                return true;
        }
        return false;
    } 
};

int main() {
    string s;
    int k;
    cin >> s >> k;
    Solution sol;
    bool result = sol.hasAllCodes(s, k);
    cout << (result ? "true" : "false") << endl;
    return 0;
}