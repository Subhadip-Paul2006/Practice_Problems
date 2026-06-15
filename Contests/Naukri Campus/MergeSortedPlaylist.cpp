/* A music application maintains two playlists, Playlist A and Playlist B, where the song durations in each playlist are already sorted in non-decreasing order.

Merge the two playlists into a single playlist such that:

All songs from both playlists are included exactly once.
The resulting playlist remains sorted in non-decreasing order of duration.

Return the head of the merged sorted playlist.*/

/* Input Format:
01. First line contains integer N1, the number of songs in Playlist A.
02. Next N1 lines contain the song durations of Playlist A.
03. Next line contains integer N2, the number of songs in Playlist B.
04. Next N2 lines contain the song durations of Playlist B.
Both playlists are already sorted.
*/

/*Output Format:
Print the song durations of the merged sorted playlist, one per line.
*/

/* Constraints:
0 ≤ N1, N2 ≤ 10^5
1 ≤ duration ≤ 10^9 */

/*Sample Input:
4 1 3 5 7 4 2 4 6 8
Sample Output:
1 2 3 4 5 6 7 8 */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int value) {
        data = value;
        next = nullptr;
    }
};

SinglyLinkedListNode* mergePlaylists(
    SinglyLinkedListNode* list1,
    SinglyLinkedListNode* list2)
{
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* tail = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != nullptr)
    {
        tail->next = list1;
    }
    if (list2 != nullptr)
    {
        tail->next = list2;
    }

    return dummy->next;
}

void printList(SinglyLinkedListNode* head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    int n1;
    cin >> n1;

    SinglyLinkedListNode* list1 = nullptr;
    SinglyLinkedListNode* tail1 = nullptr;

    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;

        SinglyLinkedListNode* node = new SinglyLinkedListNode(x);

        if (list1 == nullptr)
        {
            list1 = tail1 = node;
        }
        else
        {
            tail1->next = node;
            tail1 = node;
        }
    }

    int n2;
    cin >> n2;

    SinglyLinkedListNode* list2 = nullptr;
    SinglyLinkedListNode* tail2 = nullptr;

    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;

        SinglyLinkedListNode* node = new SinglyLinkedListNode(x);

        if (list2 == nullptr)
        {
            list2 = tail2 = node;
        }
        else
        {
            tail2->next = node;
            tail2 = node;
        }
    }

    SinglyLinkedListNode* result = mergePlaylists(list1, list2);

    printList(result);

    return 0;
}