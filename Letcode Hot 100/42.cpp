// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

// 示例 1：



// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 示例 2：

// 输入：height = [4,2,0,3,2,5]
// 输出：9
 

// 提示：

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105


/// 【动态规划】
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        // 每个位置左右两边的最大高度
        int leftMax[20010];
        int rightMax[20010];
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for(int i=1 ; i<n ; i++)
            leftMax[i] = max(height[i], leftMax[i-1]);
        for(int i=n-2 ; i>=0 ; i--)
            rightMax[i] = max(height[i], rightMax[i+1]);

        int ans = 0;
        for(int i=1 ; i<n-1 ; i++)
            ans += min(leftMax[i], rightMax[i]) - height[i];

        return ans;
    }
};


/// 【双指针】
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        int lMax = 0, rMax = 0;
        while(l < r)
        {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);
            if(height[l] < height[r])//必有 leftMax<rightMax
            {
                ans += lMax - height[l];
                l++;
            }
            else//必有 leftMax≥rightMax
            {
                ans += rMax - height[r];
                r--;
            }
        }
        return ans;
    }
};