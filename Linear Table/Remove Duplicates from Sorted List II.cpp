/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-15 
Description: leetcode上Remove Duplicates from Sorted List II解答
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
        if(!head||!head->next) return head;
        
        int val=head->val;
        ListNode* p=head->next;
        //没有出现重复，很安全
        if(p->val!=val){
            head->next=deleteDuplicates(p);
            return head;
        }
        //出现了重复，根据公式deleteDuplicates(p(duplicate))==deleteDuplicates(p'(一直往后直到是unique))
        else{
            while(p&&p->val==val) p=p->next;
            return deleteDuplicates(p);
            
    }
        }
};
