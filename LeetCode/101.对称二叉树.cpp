struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return (root == nullptr || judge(root->left,root->right));
    }
    bool judge(TreeNode* L,TreeNode* R){
        if(L==nullptr && R==nullptr)
            return true;
        if(L==nullptr || R==nullptr || L->val != R->val)
            return false;
        return judge(L->left,R->right) && judge(R->left,L->right);
    }
};