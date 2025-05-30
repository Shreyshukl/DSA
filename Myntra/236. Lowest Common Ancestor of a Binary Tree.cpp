class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL)
       {
        return NULL;
       }
       if(root == p || root == q)
       {
        return root;
       }
       TreeNode* left = lowestCommonAncestor(root->left , p ,q);
       TreeNode* right = lowestCommonAncestor(root->right , p ,q);
       if(left&&right)
       {
        return root;
       }
       if(right)
       {
        return right;
       }

       return left;
    }
};
