/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-15
Description: leetcode上Rotate List解答
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0) return head;
        
        int len=1;
        ListNode* p=head;
        while(p->next){
            len++;
            p=p->next;
        }
        //考虑到题给k可能会大于等于链表长度
        k=len-k%len;
        //上述循环结束之后最后一个p指向链表最后一个元素
        
        //连城了一个环
        p->next=head;
        for(int i=0;i<k;i++){
            p=p->next;
        }
        //下面两行代码从中间截断
        head=p->next;
        p->next=nullptr;
        return head;
    }
};
