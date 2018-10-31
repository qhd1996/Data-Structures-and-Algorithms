/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
 标化方法，先顺序遍历再进行zigzag变换。
 **/
class Solution {
public:
    vector<vector<int> > res;
    void zigzag(TreeNode* root,int depth){
        if(root==nullptr) return;
        if(res.size()==depth){
            res.push_back(vector<int>());      
        }
        res[depth].push_back(root->val);
       
        zigzag(root->left,depth+1);
        zigzag(root->right,depth+1); 
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzag(root,0);
        
        for(int i=0;i<res.size();i++){
            if(i%2==1)
                reverse(res[i].begin(),res[i].end());
        }
        
        return res;
    }
};
