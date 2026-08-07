// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：

// 输入：n = 1
// 输出：["()"]
 

// 提示：

// 1 <= n <= 8


/// 【dfs】典型的dfs，注意右括号必须要和左括号配对，且不能超过左括号的数量
class Solution {
public:
    vector<string> ans;
    // 对于字符串u的dfs。（还剩l个，）还剩r个
    void dfs(string u, int l, int r)
    {
        if(l==0 && r==0)
        {
            ans.push_back(u);
            return;
        }
        if(l == r)
            dfs(u+'(', l-1, r);
        else if(l < r)
        {
            if(l)
                dfs(u+'(', l-1, r);
            if(r)
                dfs(u+')', l, r-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(s, n, n);
        return ans;
    }
};