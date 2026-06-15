// Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
// Recall that the number of set bits an integer has is the number of 1's present when written in binary.
// For example, 21 written in binary is 10101, which has 3 set bits.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;
        for(int i = left; i <= right; i++){
            int setbits = __builtin_popcount(i);
            if (primes.count(setbits)){
                count++;
            }
        }
        return count;
    }
};

int main() {
    int left, right;
    cin >> left >> right;
    Solution sol;
    cout << sol.countPrimeSetBits(left, right) << endl;
    return 0;
}