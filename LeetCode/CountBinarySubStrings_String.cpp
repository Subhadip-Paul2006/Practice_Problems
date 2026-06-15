// Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times they occur.

#include <iostream>
#include <vector>
using namespace std;

int countBinarySubstrings(string s) {
    vector<int> groups;
    int count = 1;

    // Step 1: Count consecutive characters
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            groups.push_back(count);
            count = 1;
        }
    }
    groups.push_back(count); // last group

    // Step 2: Count valid substrings
    int result = 0;
    for (int i = 1; i < groups.size(); i++) {
        result += min(groups[i], groups[i - 1]);
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cout << countBinarySubstrings(s);
    return 0;
}
