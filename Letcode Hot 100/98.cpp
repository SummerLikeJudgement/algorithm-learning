// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

// 有效 二叉搜索树定义如下：

// 节点的左子树只包含 严格小于 当前节点的数。
// 节点的右子树只包含 严格大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
 

// 示例 1：


// 输入：root = [2,1,3]
// 输出：true
// 示例 2：


// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 

// 提示：

// 树中节点数目范围在[1, 104] 内
// -231 <= Node.val <= 231 - 1


///【回溯】注意最大值和最小值的类型要是long long
class Solution {
public:
    // 节点u为根的树作为子树是否满足要求
    bool dfs(TreeNode* u, long long Min, long long Max)
    {
        if(u == nullptr)
            return true;
        if(u->val<=Min || u->val>=Max)
            return false;
        bool flag = true;
        // 左子树
        if(u->left && flag)
            flag = flag && dfs(u->left, Min, min(Max, (long long)u->val));
        // 右子树
        if(u->right && flag)
            flag = flag && dfs(u->right, max(Min, (long long)u->val), Max);
        return flag;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
///【bfs】时间复杂度$O(N)$。对二叉搜索树进行中序遍历得到的序列是升序序列，可由此判断。
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};