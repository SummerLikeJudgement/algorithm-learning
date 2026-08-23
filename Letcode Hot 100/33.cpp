// 整数数组 nums 按升序排列，数组中的值 互不相同 。

// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。

// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

// 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

 

// 示例 1：

// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4
// 示例 2：

// 输入：nums = [4,5,6,7,0,1,2], target = 3
// 输出：-1
// 示例 3：

// 输入：nums = [1], target = 0
// 输出：-1
 

// 提示：

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// nums 中的每个值都 独一无二
// 题目数据保证 nums 在预先未知的某个下标上进行了旋转
// -104 <= target <= 104


/// 【整数二分】利用二分找到大于等于nums[0]的区间的右端点即可
class Solution {
public:
    int bsearch(vector<int>& nums, int target, int l, int r)
    {
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        // k=0时，未进行旋转
        if(nums[l] < nums[r])
            l = r;
        // k>0时，进行了旋转
        // 找到大于nums[0]区间的右端点
        while(l < r)
        {
        int mid = l + r + 1 >> 1;
        if(nums[mid]>nums[0])
            l = mid;
        else
            r = mid - 1;
        }
        if(target>=nums[0] && target<=nums[l])
        {
            int ans = bsearch(nums, target, 0, l);
            if(nums[ans] == target)
                return ans;
        }
        if(l+1<n && target>=nums[l+1] && target<=nums[n-1])
        {
            int ans = bsearch(nums, target, l+1, n-1);
            if(nums[ans] == target)
                return ans;
        }
        return -1;
    }
};