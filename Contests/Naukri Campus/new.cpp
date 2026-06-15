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