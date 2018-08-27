/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-15 
Description: leetcode上Remove Nth Node From End of List解答
**************************************************/
/**
*这题其实就是找出一个链表中找出第k个元素，是常见的问题，一定要数量掌握。
*设两个指针p和q,先让q走k步，然后p、q一起走，直至q走到尾节点，删除p->next即可，时间复杂度O(n),空间复杂度O(1)。
**/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* p=&dummy,*q=&dummy;
        
        for(int i=0;i<n;i++)
            q=q->next;
        
        while(q->next){
            p=p->next;
            q=q->next;
        }
        ListNode* tmp=p->next;
        p->next=p->next->next;
        delete tmp;
        return dummy.next;
        
    }
};
