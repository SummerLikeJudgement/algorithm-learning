// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

// 示例 1:



// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10
// 示例 2：



// 输入： heights = [2,4]
// 输出： 4
 

// 提示：

// 1 <= heights.length <=105
// 0 <= heights[i] <= 104


/// 【单调栈】不要枚举区间，而是枚举“每个柱子作为最矮柱子时，能向左右扩展多远”。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> s;
        vector<int> lMin(n);// 为避免后面越界访问，需要分配长度n!
        vector<int> rMin(n);
        // 找到每处左边第一个小于的元素
        for(int i=0 ; i<n ; i++)
        {
            while(s.size() && heights[s.top()]>=heights[i])// 要找的是“第一个严格小于当前高度”的位置,相等高度的柱子应该合并成更宽的矩形。
                s.pop();
            if(s.size())
                lMin[i] = s.top();
            else
                lMin[i] = -1;
            s.push(i);
        }
        while(s.size())
            s.pop();
        // 找到每处右边第一个小于的元素
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(s.size() && heights[s.top()]>=heights[i])
                s.pop();
            if(s.size())
                rMin[i] = s.top();
            else
                rMin[i] = n;
            s.push(i);
        }
        for(int i=0 ; i<n ; i++)
            ans = max(heights[i]*(rMin[i]-lMin[i]-1), ans);
        return ans;
    }
};