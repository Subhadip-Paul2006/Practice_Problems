// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
// If the current number is even, you have to divide it by 2.
// If the current number is odd, you have to add 1 to it.
// It is guaranteed that you can always reach one for all test cases.
// Example 1:
// Input: s = "1101"
// Output: 6

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') 
            {
                s.pop_back();
            }
            else 
            {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1')
                {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) {
                    s = '1' + s; 
                } 
                else 
                {
                    s[i] = '1';
                }
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution sol;
    string s = "1101";
    int result = sol.numSteps(s);
    cout << "Number of steps to reduce " << s << " to 1: " << result << endl;
    return 0;
}