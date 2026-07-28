// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

// 示例 1：


// 输入：root = [1,null,2,3]
// 输出：[1,3,2]
// 示例 2：

// 输入：root = []
// 输出：[]
// 示例 3：

// 输入：root = [1]
// 输出：[1]
 

// 提示：

// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
 

// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？


/// 【dfs/回溯】
class Solution {
public:
    vector<int> ans;
    // 在节点u处的dfs
    void dfs(TreeNode* u)
    {
        if(u == nullptr)
            return;
        if(u->left)
            dfs(u->left);
        ans.push_back(u->val);
        if(u->right)
            dfs(u->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};


/// 【迭代】
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || s.size())
        {
            // 将所有左边节点入栈
            while(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            // 左子树为空，中间+右节点
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};