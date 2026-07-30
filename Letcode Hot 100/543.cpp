// 给你一棵二叉树的根节点，返回该树的 直径 。

// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

// 两节点之间路径的 长度 由它们之间边数表示。

 

// 示例 1：


// 输入：root = [1,2,3,4,5]
// 输出：3
// 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
// 示例 2：

// 输入：root = [1,2]
// 输出：1
 

// 提示：

// 树中节点数目在范围 [1, 104] 内
// -100 <= Node.val <= 100


/// 【dfs】dfs计算以节点u为起点的最大路径（左右子树选一个），在dfs中计算全局的最大值
class Solution {
public:
    int ans = 0;
    // 以节点u为起点的最大路径（左右子树选一个）
    int dfs(TreeNode* u)
    {
        if(u == nullptr)
            return 0;
        int l = 0, r = 0;
        if(u->right)
            r = 1 + dfs(u->right);
        if(u->left)
            l = 1 + dfs(u->left);
        ans = max(ans, l + r);
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};