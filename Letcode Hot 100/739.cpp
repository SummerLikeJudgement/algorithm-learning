// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 

// 示例 1:

// 输入: temperatures = [73,74,75,71,69,72,76,73]
// 输出: [1,1,4,2,1,1,0,0]
// 示例 2:

// 输入: temperatures = [30,40,50,60]
// 输出: [1,1,1,0]
// 示例 3:

// 输入: temperatures = [30,60,90]
// 输出: [1,1,0]
 

// 提示：

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100


/// 【单调栈】从后往前遍历数组，维护值的单调栈和记录下标的栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;// 记录值
        stack<int> p;// 记录下标
        vector<int> ans;
        int n = temperatures.size();
        // init
        ans.push_back(0);// 最后元素一定为0
        s.push(temperatures[n-1]);
        p.push(n-1);
        for(int i=n-2 ; i>=0 ; i--)
        {
            int t = temperatures[i];
            while(s.size()>0 && s.top()<=t)
            {
                s.pop();
                p.pop();
            }
            if(s.size())// 有大于t的值
                ans.push_back(p.top()-i);
            else// 没有大于t的值
                ans.push_back(0);
            s.push(t);
            p.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


/// 【单调栈】优化版本，从栈底到栈顶的下标对应的温度依次递减，如果下标在单调栈里，则表示尚未找到下一次温度更高的下标。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};