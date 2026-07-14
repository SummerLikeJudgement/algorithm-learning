// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

// 算法的时间复杂度应该为 O(log (m+n)) 。

 

// 示例 1：

// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
// 示例 2：

// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 

 

// 提示：

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

/// 【二分】抽象二分。合并两数组+二分或双指针的方法时间复杂度都是O(M+N)，不符合题目要求。
/// 中位数的本质是将数组分为左右两半，两边元素数量相等。并且可以在两个数组分别切出左部右部数量相等并且使其满足left1<=right2 left2<=right1即是中位数
/// 所以可以利用二分查找一个数组的划分（另一个数组也就确定了）是否满足要求，如果不满足则更新
/// 注意l和r的初始取值！！
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // 奇数时，左部比右部少一个元素
        int totalleft = (m+n) >> 1;
        // 对nums1进行二分
        int l = max(0, totalleft-n); // nums1左部最少有totalleft-n个元素
        int r = min(m,totalleft); // nums1左部最多有totalleft个元素
        while(l<=r)
        {
            int i = l + (r-l)/2; // nums1的左部元素数量
            int j = totalleft-i;// nums2的左部元素数量
            // nums1的左部右部边界元素
            int lMax1 = (i==0) ? INT_MIN : nums1[i-1];
            int rMin1 = (i==m) ? INT_MAX : nums1[i];
            // nums2的左部右部边界元素
            int lMax2 = (j==0) ? INT_MIN : nums2[j-1];
            int rMin2 = (j==n) ? INT_MAX : nums2[j];
            if(lMax1<=rMin2 && lMax2<= rMin1) // 满足左部小于右部
            {
                // 计算中位数
                if((m+n) % 2 == 1) // 奇数时
                    return (double)min(rMin1, rMin2);
                    // return (double)max(lMax1, lMax2));
                else // 偶数时
                {
                    return (double)((min(rMin1, rMin2) + max(lMax1, lMax2)) / 2.0);
                }
            }
            // 不满足时，说明i到左侧或右侧一定全部不成立
            else if(lMax1>rMin2)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }
        
        return 0.0;
    }
};