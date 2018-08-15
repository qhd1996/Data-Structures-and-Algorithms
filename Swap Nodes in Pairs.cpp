



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
*强烈推荐看一看，我的见解是他把一级指针当成普通的变量来处理了。
**/
class Solution{
ListNode* swapPairs(ListNode* head) {
       ListNode **p=&head, *ptr=nullptr;
       while ((*p)&&(*p)->next) {
           ptr=(*p)->next->next;
           (*p)->next->next=(*p);
     ，      (*p)=(*p)->next;
           (*p)->next->next=ptr;
           p=&((*p)->next->next);       
       }
       return head;
   }
}
