// Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.
// Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.

#include <iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int pos = 0;
        int ans = 0;
        while(n > 0){
            if(n & 1){
                if(last != -1){
                    ans = max(ans, pos - last);
                }
                last = pos;
            }
            n >>= 1;
            pos++;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.binaryGap(n) << endl;
    return 0;
}