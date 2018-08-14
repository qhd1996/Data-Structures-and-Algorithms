/************************************************* 
License: Apache 2.0
Author: 錢昊達
Date: 2018-08-14 
Description: leetcode上Add Two Numbers II解答
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
    ListNode* addLists (ListNode* l1, ListNode* l2) {
	// 辅助函数，两个长度相同的List相加
        if(l1==nullptr&&l2==nullptr) return nullptr;
        //先算低位的加法，这样才能保证进位可以传递到高位
        ListNode* n = addLists(l1->next, l2->next);
        int cur = l1->val + l2->val;
        if (n && n->val > 9) {
            cur += 1;
            n->val %= 10;
        }
        ListNode* c = new ListNode(cur);
        c->next = n;
        return c;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ll1 = 0, ll2 = 0;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        // 计算每个List的长度
		while (tmp1) {
            tmp1 = tmp1->next;
            ll1++;
        }
        while (tmp2) {
            tmp2 = tmp2->next;
            ll2++;
        }
	//长度不一样就加零使得两个List长度相同
        if (ll1 > ll2) {
            while (ll1 > ll2++) {
                ListNode* tmp = new ListNode(0);
                tmp->next = l2;
                l2 = tmp;
            }
        } else if (ll2 > ll1) {
            while (ll2 > ll1++) {
                ListNode* tmp = new ListNode(0);
                tmp->next = l1;
                l1 = tmp;
            }
        }
        // We add the two lists and in case they have in the first node 
				// number > 9 we add one more node (1).
        ListNode* res = addLists(l1, l2);
        //最高位是否有进位
        if (res && res->val > 9) {
            res->val %= 10;
            ListNode* r = new ListNode(1);
            r->next = res;
            return r;
        }
        return res;
    }
};
