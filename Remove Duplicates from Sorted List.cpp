/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-15 
Description: Remove Duplicates from Sorted List解答
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        //dummy的val只需要和head不一样即可
        ListNode dummy(head->val+1);
        dummy.next=head;
        recur(&dummy,head);
        return dummy.next;
    }
private:
    void recur(ListNode* prev,ListNode* cur){
        if(cur==nullptr) return;
        if(prev->val==cur->val){
            prev->next=cur->next;
            delete cur;
            recur(prev,cur->next);
        }else{
            recur(prev->next,cur->next);
        }
    }
};
