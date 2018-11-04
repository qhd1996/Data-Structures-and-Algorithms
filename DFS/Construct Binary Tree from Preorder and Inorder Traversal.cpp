/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
    
    TreeNode* helper(vector<int>& preorder,int phead,int pend,vector<int>& inorder,int ihead,int iend){
        if(phead>=pend||ihead>=pend)
            return nullptr;
        
        int mid=preorder[phead];
        auto f=find(inorder.begin()+ihead,inorder.begin()+iend,mid);
        int dis=f-inorder.begin()-ihead;
        
        TreeNode* root=new TreeNode(mid);
        root->left=helper(preorder,phead+1,phead+1+dis,inorder,ihead,ihead+dis);
        root->right=helper(preorder,phead+1+dis,pend,inorder,ihead+1+dis,iend);
        return root;
    }
    
};
