// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

// 示例 1:

// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4
 

// 提示：

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104


/// 【大根堆】时间复杂度O(NlogN)
class Solution {
public:
    static const int N = 1e5+10;
    int h[N], size_; // 大根堆
    // 尝试将x位置的值向下到正确的位置
    void down(int x)
    {
        int t = x;
        if(2*x <= size_ && h[2*x] > h[t]) t = 2*x;
        if(2*x+1 <= size_ && h[2*x+1] > h[t]) t = 2*x+1;

        if(t!=x)
        {
            swap(h[x], h[t]);
            down(t);
        }
    }
    // 尝试将x位置的值向上到正确位置
    void up(int x)
    {
        while(x/2 && h[x]>h[x/2])
        {
            swap(h[x], h[x/2]);
            x /= 2;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        // 初始化大根堆
        size_ = nums.size();
        for(int i=1 ; i<=size_ ; i++)
            h[i] = nums[i-1];
        for(int i=size_/2 ; i ; i--)
            down(i);
        while(--k)
        {
            swap(h[1], h[size_]);
            size_--;
            down(1);
        }
        return h[1];
    }
};



/// 【快排->快速选择】
class Solution {
public:
    // 在q的[l,r]中找到最终下标为k的数
    int quick_select(int q[], int l, int r, int k)
    {
        if(l == r) return q[l]; 
        int i = l-1, j = r+1;
        int base = q[l];

        while(i<j)
        {
            while(q[++i] < base){}
            while(q[--j] > base){}

            if(i<j)
                swap(q[i], q[j]);
        }

        if(k <= j) 
            return quick_select(q, l, j, k);
        else 
            return quick_select(q, j+1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int q[100010];
        int cnt = nums.size();
        for(int i=0 ; i<cnt ; i++)
            q[i] = nums[i];

        int ans = quick_select(q, 0, cnt-1, cnt-k);

        return ans;
    }
};