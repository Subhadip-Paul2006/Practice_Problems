// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

// Example 1:
// Input: n = 1, k = 3
// Output: "c"


#include <iostream>
#include <vector>   
#include <string>
using namespace std;

class Solution {
public:
    void dfs(int n, int k, string &curr, vector<string> &ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                curr.push_back(c);
                dfs(n,k,curr,ans);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        
        vector<string> ans;
        string curr="";

        dfs(n,k,curr,ans);

        if(ans.size() < k) return "";
        
        return ans[k-1];
    }
    
};

int main() {
    Solution sol;
    int n = 1, k = 3;
    string result = sol.getHappyString(n, k);
    cout << "The " << k << "rd happy string of length " << n << " is: " << result << endl;
    return 0;
}