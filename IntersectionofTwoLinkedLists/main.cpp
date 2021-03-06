/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int aLen = 1;
        ListNode* p = headA;
        while(p->next != NULL)
        {
            aLen++;
            p = p->next;
        }
        ListNode* pa = p;
        int bLen = 1;
        p = headB;
        while(p->next != NULL)
        {
            bLen++;
            p = p->next;
        }
        ListNode* pb = p;
        if (pa != pb)
        {
            return NULL;
        }
        pa = headA;
        pb = headB;
        if (aLen > bLen)
        {
            pa = moveSteps(headA, aLen - bLen);
        }
        else if (aLen < bLen)
        {
            pb = moveSteps(headB, bLen - aLen);
        }
        while (pa != NULL && pb != NULL)
        {
            if (pa == pb)
            {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
    }
private:
    ListNode* moveSteps(ListNode* head, int steps)
    {
        for (int i = 0; i < steps && head != NULL; i++)
        {
            head = head->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
