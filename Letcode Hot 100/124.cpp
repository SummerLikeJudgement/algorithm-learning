// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

 

// 示例 1：


// 输入：root = [1,2,3]
// 输出：6
// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
// 示例 2：


// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 

// 提示：

// 树中节点数目范围是 [1, 3 * 104]
// -1000 <= Node.val <= 1000


/// 【递归】利用递归计算每个节点为起点的路径最大值。注意可以在递归函数中就计算所有路径的最大值！
class Solution {
public:
    int ans = INT_MIN;
    // 节点u为起点的路径最大值(左右子树只能选一个)
    int dfs(TreeNode* u)
    {
        if(u == nullptr)
            return 0;
        int sum = u->val;
        int l = max(dfs(u->left), 0);
        int r = max(dfs(u->right), 0);
        sum += l + r;
        // 在dfs过程中找到最大路径
        ans = max(ans, sum);
        return u->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};