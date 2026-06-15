// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
// Example 1:
// Input: nums = ["01","10"]
// Output: "11"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            if(nums[i][i] == '0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> nums = {"01", "10"};
    string result = sol.findDifferentBinaryString(nums);
    cout << "A binary string that does not appear in nums is: " << result << endl;
    return 0;
}