
class Solution {
public:
     unordered_map<TreeNode*,int>mp; 
    //to store the maximum money that can be robbed starting from a given node.
       
    int rob(TreeNode* root) {
    
        if(root==NULL)
        {
            return 0;
        }
        if(mp.find(root)!=mp.end())
        {
            return mp[root];
        }
        //case I : include root;
        int includeRoot = root->val;
        if(root->left)
        {
            includeRoot+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right)
        {
            includeRoot+= rob(root->right->left)+rob(root->right->right);
        }

        int excludeRoot = rob(root->left) + rob(root->right);

        return mp[root]=max(includeRoot,excludeRoot);
    }
};
