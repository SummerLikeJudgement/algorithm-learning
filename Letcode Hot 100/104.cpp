// 给定一个二叉树 root ，返回其最大深度。

// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

 

// 示例 1：



 

// 输入：root = [3,9,20,null,null,15,7]
// 输出：3
// 示例 2：

// 输入：root = [1,null,2]
// 输出：2
 

// 提示：

// 树中节点的数量在 [0, 104] 区间内。
// -100 <= Node.val <= 100

/// 【dfs】简单的dfs
class Solution {
public:
    // 节点u下的dfs
    int dfs(TreeNode* u)
    {
        int ldepth = 0, rdepth = 0;
        if(u->left)
            ldepth = dfs(u->left);
        if(u->right)
            rdepth = dfs(u->right);
        return max(ldepth, rdepth)+1;
    }
    int maxDepth(TreeNode* root) {
        if(root) // 注意边界情况！
            return dfs(root);
        else
            return 0;
    }
};