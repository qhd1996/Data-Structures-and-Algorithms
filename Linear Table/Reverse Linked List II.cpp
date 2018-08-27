/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date:2010-08-25 
Description: leetcode上Reverse Linked List II解答
**************************************************/  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//这题的难点在于边界检查
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //边界情况，收尾相同
        if(m==n) return head;
        ListNode dummy=ListNode(-1);
        dummy.next=head;
        ListNode* prev=&dummy;
        for(int i=0;i<m-1;i++){
            prev=prev->next;
        }
        //此时的head2是List中第m-1个位置
        ListNode* const head2=prev;
        //反转开始位置
        prev=head2->next;
        ListNode *cur=prev->next;
        for(int i=m;i<n;i++){
            prev->next=cur->next;
            cur->next=head2->next;
            head2->next=cur;
            //头插法
            cur=prev->next;
        }
        return dummy.next;
    }
};
