/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 **
 *在递归函数中，如果当前结点不存在，那么直接返回0。否则就分别对其左右子节点调用递归函数，如果路径和是负数，我们就加0，如果路径和是正数我们就加路径和。
 *然后我们来更新全局最大值结果res，就是以左子结点为终点的最大path之和加上以右子结点为终点的最大path之和，还要加上当前结点值，这样就组成了一个条完整的路径。而我们返回值是取left和right中的较大值加上当前结点值，因为我们返回值的定义是以当前结点为终点的path之和，所以只能取left和right中较大的那个值，而不是两个都要
 **
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
    
    int helper(TreeNode *node,int &res){
        if(node==nullptr) return 0;
        int left=max(helper(node->left,res),0);
        int right=max(helper(node->right,res),0);
        res=max(res,left+right+node->val);
        return max(left,right)+node->val;
    }
};
