// 给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

 

// 示例 1：

// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
// 示例 2：

// 输入：s = "a"
// 输出：[["a"]]
 

// 提示：

// 1 <= s.length <= 16
// s 仅由小写英文字母组成


/// 【dfs+动态规划】要给出方案具体的分割方式，故使用dfs枚举所有的方案+使用动态规划找到所有子串是否为回文串
class Solution {
public:
    bool f[20][20]; // 表示[i,j]是否为回文串
    vector<vector<string>> ans;
    vector<string> now;
    void dfs(string &s, int u)// 字符串s中下标u处的dfs([0,u-1]已经找到了回文串的分割)
    {
        int n = s.size();
        if(u >= n)
            ans.push_back(now);
        for(int j=u ; j<n ; j++)
        {
            if(f[u][j])
            {
                now.push_back(s.substr(u,j-u+1));
                dfs(s, j+1);
                now.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // init
        memset(f, true, sizeof f);

        for(int i=n-1 ; i>=0 ; i--)
            for(int j=i+1 ; j<n ; j++)// j>i
                f[i][j] = f[i+1][j-1] && (s[i]==s[j]);

        dfs(s, 0);

        return ans;
    }
};