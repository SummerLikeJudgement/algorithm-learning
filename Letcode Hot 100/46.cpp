// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 示例 2：

// 输入：nums = [0,1]
// 输出：[[0,1],[1,0]]
// 示例 3：

// 输入：nums = [1]
// 输出：[[1]]
 

// 提示：

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// nums 中的所有整数 互不相同


/// 【dfs】经典回溯问题
const int N = 10;

class Solution {
public:
    bool use[N];
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int>& u)
    {
        // 排列完成
        if(u.size() == nums.size())
            ans.push_back(u);
        for(int t=0 ; t<nums.size() ; t++)
        {
            if(use[t])
                continue;
            use[t] = true;
            u.push_back(nums[t]);
            dfs(nums, u);
            // 恢复
            u.pop_back();
            use[t] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        dfs(nums, tmp);
        return ans;
    }
};
