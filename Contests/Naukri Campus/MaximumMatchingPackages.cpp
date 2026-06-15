/* Problem: Maximum Matching Packages
A logistics company operates two conveyor belts, Belt A and Belt B, each carrying packages in a fixed order. Every package has an associated weight.
To synchronize the belts, the company may perform the following operation any number of times on either belt:
Select a contiguous block of packages and merge them into a single package whose weight is equal to the sum of the selected block.
After performing zero or more merge operations, the two belts are considered identical if:
They contain the same number of packages.
The weight of the package at every corresponding position is the same in both belts.
Determine the maximum number of packages the belts can contain after all merge operations while still being identical.
If it is impossible to make the two belts identical, return -1.
*/

/* Input Format:
01. The first line contains an integer N, representing the number of packages on Belt A.
02. The next N lines contain the weights of the packages on Belt A.
03. The next line contains an integer M, representing the number of packages on Belt B.
04. The next M lines contain the weights of the packages on Belt B.

Output Format:
Print a single integer representing the maximum number of packages in the final identical belts.
If it is impossible to make the belts identical, print -1.

Constraits:
1 ≤ N, M ≤ 10^5
1 ≤ Package Weight ≤ 10^9
*/

/* Sample Input:
4 1 3 2 4 3 4 2 4  
Sample Output:
3
*/



#include <iostream>
#include <vector>
using namespace std;

int maxPackages(vector<int>& beltA, vector<int>& beltB)
{
    long long totalA = 0, totalB = 0;

    for (int x : beltA) totalA += x;
    for (int x : beltB) totalB += x;

    if (totalA != totalB)
        return -1;

    int i = 0, j = 0;
    long long sumA = 0, sumB = 0;
    int count = 0;

    while (i < beltA.size() || j < beltB.size())
    {
        if (sumA == sumB)
        {
            if (sumA != 0)
            {
                count++;
                sumA = 0;
                sumB = 0;
            }

            if (i < beltA.size())
                sumA += beltA[i++];

            if (j < beltB.size())
                sumB += beltB[j++];
        }
        else if (sumA < sumB)
        {
            if (i < beltA.size())
                sumA += beltA[i++];
            else
                return -1;
        }
        else
        {
            if (j < beltB.size())
                sumB += beltB[j++];
            else
                return -1;
        }
    }

    if (sumA == sumB && sumA != 0)
        count++;

    return count;
}

int main()
{
    int N;
    cin >> N;

    vector<int> beltA(N);
    for (int i = 0; i < N; i++)
        cin >> beltA[i];

    int M;
    cin >> M;

    vector<int> beltB(M);
    for (int i = 0; i < M; i++)
        cin >> beltB[i];

    cout << maxPackages(beltA, beltB);

    return 0;
}