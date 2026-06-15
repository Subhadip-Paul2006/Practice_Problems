// Special binary strings are binary strings with the following two properties:
// The number of 0's is equal to the number of 1's.
// Every prefix of the binary string has at least as many 1's as 0's.
// You are given a special binary string s.
// A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
// Return the lexicographically largest resulting string possible after applying the mentioned operations on the string s any number of times.

#include <iostream>
#include <string>       
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int start = 0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '1'){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }
        sort(parts.begin(), parts.end(), greater<string>());
        string result;
        for(const string& part : parts){
            result += part;
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;
    cout << solution.makeLargestSpecial(s);
    return 0;
}