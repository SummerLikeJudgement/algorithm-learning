// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

 

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]
// 示例 2：

// 输入：root = [1]
// 输出：[[1]]
// 示例 3：

// 输入：root = []
// 输出：[]
 

// 提示：

// 树中节点数目在范围 [0, 2000] 内
// -1000 <= Node.val <= 1000


/// 【bfs】按层遍历用bfs，注意每层的节点数就是当前size
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> q;
        // init
        q.push(root);

        while(q.size())
        {
            vector<int> tmp;
            int cnt = q.size();
            while(cnt--)
            {
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};