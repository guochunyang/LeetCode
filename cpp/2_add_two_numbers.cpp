#include <stdio.h>
#include <stdlib.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        ListNode *l3 = NULL;
        ListNode *l3_tail = NULL;

        int temp = 0; // 表示进位

        while (tmp1 != NULL && tmp2 != NULL)
        {
            //
            int val1 = tmp1->val;
            int val2 = tmp2->val;
            int val3 = val1 + val2 + temp;

            // 处理进位
            temp = val3/10;
            val3 -= temp*10;

            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = val3;
            tmp->next = NULL;

            insertList(l3, l3_tail, tmp);

            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }


        while(tmp1 != NULL)
        {
            int val = tmp1->val + temp;
            temp = val/10;
            val -= temp*10;

            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = NULL;

            insertList(l3, l3_tail, tmp);

            tmp1 = tmp1->next;
        }

        while (tmp2 != NULL)
        {
            int val = tmp2->val + temp;
            temp = val/10;
            val -= temp*10;

            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = NULL;

            insertList(l3, l3_tail, tmp);

            tmp2 = tmp2->next;
        }

        if (temp != 0)
        {
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = temp;
            tmp->next = NULL;

            insertList(l3, l3_tail, tmp);
        }

        return l3;
    }

private:

    static void insertList(ListNode *&head, ListNode *&tail, ListNode *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

};


int main()
{

}