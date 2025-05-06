class Solution {
public:
    bool isValidBST(TreeNode* root , long minval = LONG_MIN , long maxval = LONG_MAX) {
      if(root==NULL)
      {
        return true;
      }
       if(root->val<=minval || root->val>=maxval)
       {
        return false;
       }

       return isValidBST(root->left ,minval, root->val)&&isValidBST(root->right ,root->val, maxval);

    }
};
