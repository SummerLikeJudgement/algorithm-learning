// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
// 示例 1：

// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 示例 2：

// 输入：nums = [0,1,0,3,2,3]
// 输出：4
// 示例 3：

// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1
 

// 提示：

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 

// 进阶：

// 你能将算法的时间复杂度降低到 O(n log(n)) 吗?

/// 【一维动态规划】
/// 状态表示：f[i]表示前i个元素中以第i元素结尾的递增子序列的所有方案
/// 状态转移：f[i] = if(n_j>n_i) max(f[i], f[j]+1)
/// 初始化：f[1~n]=1;f[0]=0
const int N = 2505;
class Solution {
public:
    int f[N];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // init
        for(int i=0 ; i<=n ; i++)
            f[i] = 1;
        f[0] = 0;
        for(int i=2 ; i<=n ; i++)
            for(int j=1 ; j<i ; j++)
                if(nums[i-1]>nums[j-1])
                    f[i] = max(f[i], f[j]+1);
        
        int ans = 0;
        for(int i=1 ; i<=n ; i++)
            ans = max(ans, f[i]);

        return ans;
    }
};

/// 【贪心+整数二分】如果要使上升子序列尽可能的长，则需要让序列上升得尽可能慢，即要求每次在上升子序列最后加上的那个数尽可能的小。
/// 数组 d[i]表示长度为 i 的最长上升子序列的末尾元素的最小值，len记录目前最长上升子序列的长度，起始时 len 为 1，d[1]=nums[0]。
/// 依次遍历数组 nums 中的每个元素，并更新数组 d 和 len 的值。如果 nums[i]>d[len] 则更新 len=len+1，否则在 d[1…len]中找满足 d[i−1]<nums[j]<d[i] 的下标 i（二分查找），并更新 d[i]=nums[j]。
/// 注意要找d中第一个大于等于x的元素下标！否则变为最长非递减子序列！
const int N = 2505;
class Solution {
public:
    int d[N];// d[i]表示长度为i的递增子序列的最后元素的最小值
    int len; // 当前的递增子序列的最大长度
    // 找到d中第一个大于等于x的元素下标
    int find(int x)
    {
        int l = 1, r = len;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            if(d[mid] >= x)// 如果找第一个大于x的元素下标，则变成了非递减子序列！
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // init
        d[1] = nums[0];
        len = 1;

        for(int i=1 ; i<n ; i++)
            if(nums[i] > d[len])
                d[++len] = nums[i];
            else
            {
                int x = find(nums[i]);
                d[x] = nums[i];
            }
        return len;

    }
};
