// 给你一个字符串 s，找到 s 中最长的 回文 子串。

 

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
 

// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成


/// 【动态规划】回文串的判断常用动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int ansl;
        int ansr;
        // 表示[i,j]是否为回文串
        bool f[1005][1005];
        // init(i>=j时，f[i][j]=true；i<j时f为true或false不会影响计算)
        memset(f, true, sizeof f);
        for(int i=n-1 ; i>=0 ; i--)
            for(int j=i+1 ; j<n ; j++)
            {
                f[i][j] = f[i+1][j-1] && (s[i]==s[j]);
                if(f[i][j] && ans<(j-i+1))
                {
                    ans = j-i+1;
                    ansl = i;
                    ansr = j;
                }
            }
        // 没有长度超过1的回文串
        if(ans == 0)
            return s.substr(0, 1);
        else
            return s.substr(ansl, ans);
    }
};