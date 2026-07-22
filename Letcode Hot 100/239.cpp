// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

 

// 示例 1：

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：

// 输入：nums = [1], k = 1
// 输出：[1]
 

// 提示：

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


/// 【大根堆】初始窗口的所有{元素，下标}加入大根堆，移动窗口时加入右侧新元素，堆顶下标不在当前窗口中时弹出直到在窗口中，堆顶即是窗口最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // 大根堆
        priority_queue<pair<int, int>> q;// num, idx
        int l=0 , r=k-1;
        for(int i=l ; i<r ; i++)
            q.push({nums[i], i});
        while(r<nums.size())
        {
            q.push({nums[r],r});
            // 弹出窗口外的元素
            while(q.top().second < l)
                q.pop();
            ans.push_back(q.top().first);
            r++;
            l++;
        }
        return ans;
    }
};


/// 【单调队列】i<j且nums[i]≤nums[j]时，nums[i]是无用元素。可维护满足i<j且nums[i]>nums[j]的队列，队首就是最大值，同样的，队首不在当前窗口中时弹出直到在窗口中，队首即是窗口最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // 单调队列（双端队列）
        deque<int> q;// 存放下标
        for(int i=0 ; i<k-1 ; i++)
        {
            while(q.size() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        int l=0, r=k-1;
        while(r<nums.size())
        {
            while(q.size() && nums[q.back()] <= nums[r])
                q.pop_back();
            q.push_back(r);
            while(q.front() < l)
                q.pop_front();
            ans.push_back(nums[q.front()]);
            l++;
            r++;
        }
        return ans;
    }
};