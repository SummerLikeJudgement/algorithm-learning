// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

 

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2
 

// 提示：

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107


/// 【前缀和+哈希】使用前缀和计算子数组的和，在计算前缀和的过程中利用哈希表找到以i元素结尾的子数组是否存在，有几个
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> h;// {sum, cnt}
        h[0] = 1;
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            sum += nums[i];
            ans += h[sum-k];
            h[sum]++;
        }
        return ans;
    }
};