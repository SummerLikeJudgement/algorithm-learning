// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

// 示例 1：

// 输入：nums = [3,2,3]
// 输出：3
// 示例 2：

// 输入：nums = [2,2,1,1,1,2,2]
// 输出：2
 

// 提示：
// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
// 输入保证数组中一定有一个多数元素。
 

// 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。


/// 【哈希】使用哈希表存储每个元素的出现次数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> h;
        for(int i=0 ; i<n ; i++)
        {
            ++h[nums[i]];
            if(h[nums[i]]>(n>>1))
                return nums[i];
        }
        return 0; // 不会运行到这里
    }
};


/// 【排序】排序后，第(n>>1)+1个元素一定是多数元素，其下标为n>>1
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r)
    {
        if(l>=r) return;
        int i = l-1, j = r+1;
        // 基准元素
        int x = nums[l];
        while(i<j)
        {
            while(nums[++i]<x){}
            while(nums[--j]>x){}
            if(i<j)
                swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j+1, r);
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums, 0, n-1);
        return nums[n>>1];// 第(n>>1)+1个元素一定是多数元素，其下标为n>>1
    }
};

/// 【递归/分治】如果a是nums的多数元素，将 nums 分为两部分后a必定是至少一部分的多数元素（反证法证明）。
/// 将数组分成左右两部分，分别求出左半部分的众数 a1 以及右半部分的众数 a2，随后在 a1 和 a2 中选出正确的众数。
class Solution {
public:
    // 输出[l,r]之间指定元素的数量
    int count_major(vector<int>& nums, int l, int r, int t)
    {
        int cnt = 0;
        for(int i=l ; i<=r ; i++)
            if(nums[i] == t)
                cnt++;
        return cnt;
    }

    // 找到[l,r]之间的多数元素
    int find_major(vector<int>& nums, int l, int r)
    {
        if(l>=r)
            return nums[l];
        int mid = (l+r) >> 1;
        int left = find_major(nums, l, mid);
        int right = find_major(nums, mid+1, r);
        // 左右部分多数元素相同
        if(left == right)
            return left;
        // 左右部分多数元素不同
        if(count_major(nums, l, r, left) > (r-l+1)>>1)
            return left;
        if(count_major(nums, l, r, right) > (r-l+1)>>1)
            return right;
        return -1;// 只要有多数元素，就永远不会执行到
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return find_major(nums, 0, n-1);
    }
};


/// 【Boyer-Moore 投票算法】通过不同元素间的一对一抵消，利用多数元素净优势必然存留的特性，筛选出唯一可能的候选者。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // 候选多数元素和计数
        int candicate, cnt = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(cnt == 0)
            {
                candicate = nums[i];
                cnt = 1;
            }
            else
            {
                if(candicate == nums[i])
                    cnt ++;
                else
                    cnt--;
            }
        }

        return candicate;
    }
};