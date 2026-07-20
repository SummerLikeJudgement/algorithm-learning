// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

// 示例 1：

// 输入：root = [1,2,3,null,5,null,4]

// 输出：[1,3,4]

// 解释：



// 示例 2：

// 输入：root = [1,2,3,4,null,null,null,5]

// 输出：[1,3,4,5]

// 解释：



// 示例 3：

// 输入：root = [1,null,3]

// 输出：[1,3]

// 示例 4：

// 输入：root = []

// 输出：[]

 

// 提示:

// 二叉树的节点个数的范围是 [0,100]
// -100 <= Node.val <= 100 


/// 【bfs】每层的最后一个节点就是答案
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // 0个节点
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        // bfs
        while(q.size())
        {
            int len = q.size();
            ans.push_back(q.back()->val);
            for(int i=0 ; i<len ; i++)
            {
                auto t = q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);    
            }
        }
        return ans;
    }
};