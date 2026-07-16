// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

// 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

// 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

 

// 示例 1：

// 输入：nums = [1,3,4,2,2]
// 输出：2
// 示例 2：

// 输入：nums = [3,1,3,4,2]
// 输出：3
// 示例 3 :

// 输入：nums = [3,3,3,3,3]
// 输出：3
 

 

// 提示：

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 

// 进阶：

// 如何证明 nums 中至少存在一个重复的数字?
// 你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？

/// 【二分】cnt表示数组中小于等于i的数有多少个，可证cnt满足单增
/// 假设重复的数是t，则可证[1,t−1]满足cnt[i]≤i，[t,n]满足cnt[i]>i。二分查找cnt中第一个满足cnt[i]>i且i一定是nums中的元素
class Solution {
public:
    // nums中小于等于x的元素数量是否大于x
    bool check(int x, vector<int>& nums)
    {
        int cnt = 0;
        for(int i=0 ; i<nums.size() ; i++)
            if(nums[i] <= x)
                cnt++;
        
        return cnt > x;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=n-1;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            if(check(mid, nums))// 小于等于x的元素数量是否大于x
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};


/// 【位运算】记nums中二进制展开后第i位为1的数有x个，数字[1,n]这n个数二进制展开后第i位为1的数有y个，则t的第i位为1 == x>y
/// 可证如果重复数t第i位为1，每次替换后只会使x不变或增大，如果为0，只会使x不变或减小，始终满足x>y时t的第i位为1，否则为0
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // 找到二进制的最高位数
        int bit_max = 31;
        while(!(n-1)>>bit_max)
            bit_max--;
        
        // 计算每位的x和y
        for(int i=0 ; i<=bit_max ; i++)
        {
            int x = 0, y = 0;
            for(int j=0 ; j<n ; j++)
            {
                if(nums[j] & (1<<i))
                    x++;
                if(j>=1 && (j & (1<<i))) // 略过j=0
                    y++;
            }
            // x>y,重复数字的这个二进制位为1
            if(x > y)
                ans |= 1 << i;
        }
        return ans;
    }
};


/// 【判断环】待思考