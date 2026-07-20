// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

 

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

// 提示：

// 0 <= s.length <= 5 * 104
// s 由英文字母、数字、符号和空格组成


/// 【双指针（滑动窗口）】维护滑动窗口中所有字符只出现一次
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        bool c[300];// 记录每个字符的出现情况
        int ans = 0;
        int l = 0;
        int r = 0;
        while(r < s.size())
        {
            if(c[s[r]])// 字符已经存在
            {
                while(s[l]!=s[r])
                {
                    c[s[l]] = false;
                    l++;
                }
                l++;
            }
            else
                c[s[r]] = true;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};