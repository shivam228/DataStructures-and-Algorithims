class Solution {
public:
    int sum =0;
    int fun(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left = fun(root->left);
        int right = fun(root->right);
        int x = root->val+left +right;
        int diff  =abs(left-right);
        root->val = diff;
        return x;
    }
    void fun1(TreeNode* root)
    {
        if(root==NULL)
            return;
        sum = sum+root->val;
        fun1(root->left);
        fun1(root->right);
        
    }
    int findTilt(TreeNode* root) {
        fun(root);
        fun1(root);
        
        return sum;
        
    }
};