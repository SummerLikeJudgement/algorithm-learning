// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

// 示例 1：

// 输入：nums = [1,1,1,2,2,3], k = 2

// 输出：[1,2]

// 示例 2：

// 输入：nums = [1], k = 1

// 输出：[1]

// 示例 3：

// 输入：nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// 输出：[1,2]

 

// 提示：

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。


/// 【堆】如果将出现次数数组排序，时间复杂度为O(NlogN)，不符合要求。使用堆时间复杂度为O(NlogK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; // 小根堆{cnt, num}

        vector<int> ans;
        for(auto t=nums.begin() ; t!=nums.end() ; t++)
            h[*t]++;
        for(auto t=h.begin() ; t!=h.end() ; t++)
        {
            if(heap.size() < k)
                heap.push({t->second, t->first});
            else
            {
                if(t->second > heap.top().first)
                {
                    heap.pop();
                    heap.push({t->second, t->first});
                }
            }
        }
        while(heap.size())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};