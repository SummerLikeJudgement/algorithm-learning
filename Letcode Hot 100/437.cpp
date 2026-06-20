// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 

// 示例 1：



// 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// 输出：3
// 解释：和等于 8 的路径有 3 条，如图所示。
// 示例 2：

// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：3
 

// 提示:

// 二叉树的节点个数的范围是 [0,1000]
// -109 <= Node.val <= 109 
// -1000 <= targetSum <= 1000 


/// 【dfs+bfs】由上到下找（遍历每个点为路径最上方的点）。bfs遍历每个节点，dfs找到每个节点为根的路径数。
/// 注意为避免超出数据范围，过程中的数据要是long long
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
    //返回以u节点为起点的路径数量
    int dfs(TreeNode* u, long long target)// 为避免val相加时超出int范围所以使用long long
    {
        int cnt = 0;
        if(u->val == target)
            cnt ++;
        target = target - u->val;
        if(u->left)
            cnt += dfs(u->left, target);
        if(u->right)
            cnt += dfs(u->right, target);
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return 0;
        // 初始化
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        // BFS遍历所有节点
        while(q.size())
        {
            TreeNode* t = q.front();
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
            ans += dfs(t, targetSum);
        }
        
        return ans;
    }
};

/// 【前缀和】从下到上找（遍历每个点为路径最下方的点）。定义节点的前缀和为：由根结点到当前结点的路径上所有节点的和。更新dfs路径点的前缀和，找是否有f[cur]-f[i] == target
/// 注意i从cur-1开始遍历
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
    // vector<int, long long> prefix(1000);
    long long prefix[1010];
    // u节点处的dfs返回
    int dfs(TreeNode* u, int target, int cur)// target目标数值 cur当前层数
    {
        // 初始化
        int cnt = 0;
        prefix[cur] = prefix[cur-1] + u->val;

        for(int i = cur-1 ; i>=0 ; i--) // 注意从cur-1开始
            if(prefix[i] == prefix[cur] - target)
                cnt ++;
        if(u->left)
            cnt += dfs(u->left, target, cur+1);
        if(u->right)
            cnt += dfs(u->right, target, cur+1);

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        prefix[0] = 0;
        // root为空
        if(root == nullptr)
            return 0;
        ans += dfs(root, targetSum, 1);

        return ans;
    }
};