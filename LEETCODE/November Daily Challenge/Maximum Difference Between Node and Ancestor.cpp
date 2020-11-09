class Solution {
public:
    int fun(TreeNode* root,int min1,int max1)
    {
        if(root==NULL)
        {
            return max1-min1;
        }
         min1 = min(root->val,min1);
         max1= max(root->val,max1);
        
        int left = fun(root->left,min1,max1);
        int right = fun(root->right,min1,max1);
        return max(left,right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = fun(root,root->val,root->val);
        return ans;
    }
};