/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-15 
Description: leetcode上Swap Nodes in Pairs解答
**************************************************/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
*举个例子，现有1,2，我加一个-1，prev代表-1，cur代表1，next代表2
*我交换的是cur和next
**、/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next=head;
        
        for(ListNode* prev=&dummy,*cur=prev->next,*next=cur->next;
            next;
            prev=cur,cur=cur->next,next=cur?cur->next:nullptr){
            prev->next=next;
            cur->next=next->next;
            next->next=cur;
    }
        return dummy.next;
    }
};


/**
*leetcode上leaper大神的解法，用了二级指针，这是Linux之父Linus所推荐的一种方式。
*强烈推荐看一看，我的见解是他把一级指针当成普通的变量来处理了，那个ptr是用来保存pair之后的那个值得，方便下次从ptr指向处再次进行交换。
*举个例子，现有1,2,3，我用prt记录3的位置，*p代表1，(*p)->next代表1，(*p)->next->next就是中间变量tmp。
*我交换的是cur和next
**/
class Solution{
ListNode* swapPairs(ListNode* head) {
       ListNode **p=&head, *ptr=nullptr;
       while ((*p)&&(*p)->next) {
           ptr=(*p)->next->next;
           (*p)->next->next=(*p);
     ，    (*p)=(*p)->next;
           (*p)->next->next=ptr;
           p=&((*p)->next->next);       
       }
       return head;
   }
}
