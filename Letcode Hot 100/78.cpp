// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 示例 2：

// 输入：nums = [0]
// 输出：[[],[0]]
 

// 提示：

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// nums 中的所有元素 互不相同

/// 【位运算】0~2^n-1的二进制表示的每位的0/1分别表示不存在/存在
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        for(int i=0 ; i<pow(2,len) ; i++)
        {
            vector<int> t;
            for(int j=0 ; j<len ; j++)
            {
                if(((i>>j)&1) == 1)
                    t.push_back(nums[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};

/// 【dfs/递归】利用递归找到每种结果
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& cur, vector<int>& nums, int len)
    {
        if(len == nums.size())
        {
            ans.push_back(cur);
            return;
        }
        // 包含下一个元素
        cur.push_back(nums[len]);
        dfs(cur, nums, len+1);
        cur.pop_back();
        // 不包含下一个元素
        dfs(cur, nums, len+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(cur, nums, 0);
        return ans;
    }
};