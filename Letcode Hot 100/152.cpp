// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

// 测试用例的答案是一个 32-位 整数。

// 请注意，一个只包含一个元素的数组的乘积是这个元素的值。

 

// 示例 1:

// 输入: nums = [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:

// 输入: nums = [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 

// 提示:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// nums 的任何子数组的乘积都 保证 是一个 32-位 整数


/// 【动态规划】注意元素为负数时相乘会改变符号，所以分别维护最大和最小值
const int N = 20010;

class Solution {
public:
    // 表示以i结尾的子数组的最小乘积
    int fmin[N];
    // 表示以i结尾的子数组的最大乘积
    int fmax[N];
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        // init
        for(int i=0 ; i<n ; i++)
        {
            fmax[i] = nums[i];
            fmin[i] = nums[i];
        }
        for(int i=1 ; i<n ; i++)
        {
            int t1 = fmax[i-1] * nums[i];
            int t2 = fmin[i-1] * nums[i];
            int tmax = max(t1, t2);
            int tmin = min(t1, t2);
            fmax[i] = max(fmax[i], tmax);
            fmin[i] = min(fmin[i], tmin);
            ans = max(max(fmax[i], fmin[i]), ans);
        }
        return ans;
    }
};


/// 【动态规划】可以优化空间复杂度，从一维变为零维
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            long mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max((long)nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min((long)nums[i], mx * nums[i]));
            if(minF<INT_MIN) {
                minF=nums[i];
            }
            ans = max(maxF, ans);
        }
        return ans;
    }
};