// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

 

// 示例 1：


// 输入：root = [1,2,2,3,4,4,3]
// 输出：true
// 示例 2：


// 输入：root = [1,2,2,null,3,null,3]
// 输出：false
 

// 提示：

// 树中节点数目在范围 [1, 1000] 内
// -100 <= Node.val <= 100
 

// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？


// 【递归】
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compare(TreeNode* l, TreeNode* r)
    {
        if(l==nullptr && r==nullptr)// 都为空指针
            return true;
        else if((l && !r) || (!l && r))// 一个空一个不空
            return false;
        // 都不空
        if(l->val != r->val)
            return false;
        
        if(compare(l->left, r->right))
            if(compare(l->right, r->left))
                return true;

        return false;
            
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->right, root->left);
    }
};


// 【迭代】添加队列即可
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};