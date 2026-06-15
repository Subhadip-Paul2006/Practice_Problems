// Given a string s, find the length of the longest substring without duplicate characters.
// Input: s = "abcabcbb"
// Output: 3

#include <iostream>
#include <unordered_set>   
#include <vector> 
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++){
            char c = s[right];
            if( last[c] >= left){
                left = last[c] + 1;
            }
            last[c] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}