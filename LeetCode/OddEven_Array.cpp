// You are given an integer array of size n.
// Your task is to count how many even numbers and how many odd numbers are present in the array.
// 🔹 Input Format
// The first line contains an integer n — the size of the array
// The second line contains n space-separated integers
// 🔹 Output Format
// Print two integers:
// First, the count of even numbers
// Second, the count of odd numbers
// 🔹 Constraints
// 1 ≤ n ≤ 100
// -10^5 ≤ arr[i] ≤ 10^5

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:   
    pair<int, int> countEvenOdd(const vector<int>& arr) {
        int evenCount = 0;
        int oddCount = 0;
        for (int num : arr) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        return {evenCount, oddCount};
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    pair<int, int> result = sol.countEvenOdd(arr);
    cout << result.first << " " << result.second << endl;
    return 0;
}