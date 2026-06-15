// Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.
// To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.
// Return the following:
// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.

#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while (i < n || j < m) {
            long num1 = 0, num2 = 0;
            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (num1 < num2){
                return -1;
            }
            if (num1 > num2){
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};

int main() {
    string version1, version2;
    cin >> version1 >> version2;
    Solution solution;
    cout << solution.compareVersion(version1, version2);
    return 0;
}