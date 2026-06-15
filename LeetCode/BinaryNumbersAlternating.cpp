// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
// Example 1:
// Input: n = 5
// Output: true

#include <iostream>
using namespace std;     
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int previous = n & 1;
        while(n > 0){
            n = n >> 1;
            int current = n & 1;
            if(current == previous){
                return false;
            }
            previous = current ;
        }
        return true;
    }
};
int main() {
    int n;
    cin >> n;
    Solution solution;
    cout << boolalpha << solution.hasAlternatingBits(n);
    return 0;
}