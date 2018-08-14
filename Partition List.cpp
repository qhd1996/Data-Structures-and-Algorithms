/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-14 
Description: leetcode上Partition List解答
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
    //先分别构造值小于x的List和值大于等于x的List，再拼接两个List
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode* left_cur=&left_dummy;
        ListNode* right_cur=&right_dummy;
        for(ListNode* cur=head;cur!=nullptr;cur=cur->next){
            if(cur->val<x){
                left_cur->next=cur;
                left_cur=cur;
            }else{
                right_cur->next=cur;
                right_cur=cur;
            }
        }
        left_cur->next=right_dummy.next;
        right_cur->next=nullptr;
        return left_dummy.next;
    }
};
