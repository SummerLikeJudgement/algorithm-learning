// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

// 示例 1：

// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
// 示例 2：

// 输入：nums = [1,2,3,5]
// 输出：false
// 解释：数组不能分割成两个元素和相等的子集。
 

// 提示：

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

/// 【二维动态规划】题目要求等价于在数组中选择一些元素，使其和恰好等于sum/2。类似01背包问题。
/// 状态表示：f[i][j]表示在前i个元素中选择总和为j的方案是否存在
/// 状态转换：f[i][j] = f[i-1][j] || f[i-1][j-nums[i]]
/// 初始化：f[0][i] = false; f[i][0] = true;
const int N = 205;
const int M = 10005;
class Solution {
public:
    // 状态表示：f[i][j]表示在前i个元素中选择总和为j的方案是否存在
    // 状态转换：f[i][j] = f[i-1][j] || f[i-1][j-nums[i]]
    bool f[N][M];
    int s;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++)
            sum += nums[i];
        // 总和为奇数
        if(sum % 2 == 1)
            return false;
        // 总和为偶数
        s = sum / 2;
        // 初始化
        // f[0][i]为false
        for(int i=0 ; i<=n ; i++)
            f[i][0] = true;
        for(int i=1 ; i<=n ; i++)
            for(int j=0 ; j<=s ; j++)
            {
                f[i][j] = f[i-1][j];
                if(j >= nums[i-1])
                    f[i][j] = (f[i][j] || f[i-1][j-nums[i-1]]);
            }
        return f[n][s];
    }
};


/// 【一维动态规划】类似于01背包问题的一维优化。
const int M = 10005;
class Solution {
public:
    bool f[M];
    int s;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++)
            sum += nums[i];
        // 总和为奇数
        if(sum % 2 == 1)
            return false;
        // 总和为偶数
        s = sum / 2;
        // 初始化
        f[0] = true;
        for(int i=1 ; i<=n ; i++)
            for(int j=s ; j>=nums[i-1] ; j--) // 直接限制j的范围
                f[j] = f[j] || f[j-nums[i-1]];
        return f[s];
    }
};