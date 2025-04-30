
class Solution {
public:
int deepestLeavesSum(struct TreeNode* root) {
   if(root==NULL)
   {
    return 0;
   }
   queue<TreeNode*>q;
   q.push(root);
   int levelSum = 0;
   while(!q.empty())
   {
      int size = q.size();
       levelSum = 0;
      for(int i = 0 ; i<size ; i++)
      {
        TreeNode*temp = q.front();
        q.pop();
        levelSum+=temp->val;
        if(temp->left)
        {
            q.push(temp->left);
        } 
        if(temp->right)
        {
            q.push(temp->right);
        } 
      }
   }
    return levelSum;
}
};
