// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

 

// 示例 1:

// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 解释：

// 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
// 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
// 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
// 示例 2:

// 输入: strs = [""]

// 输出: [[""]]

// 示例 3:

// 输入: strs = ["a"]

// 输出: [["a"]]

 

// 提示：

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] 仅包含小写字母


/// 【排序+哈希】
/// 遍历所有的string，将其排序后存入hash表
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int cnt = 0;
        unordered_map<string, int> h;
        // 
        for(auto t=strs.begin() ; t!=strs.end() ; t++)
        {
            string temp = *t;
            sort(temp.begin(), temp.end());
            if(h.find(temp) != h.end())
            {
                int pos = h[temp];
                ans[pos].push_back(*t);
            }
            else
            {
                int pos = cnt++;
                h[temp] = pos;
                ans.push_back({});
                ans[pos].push_back(*t);
            }
        }

        return ans;
    }
};
/// 可优化：直接unorder_map<string, vector<string>>，但最后还要遍历hash构建出vector<vector<string>>


/// 【计数+哈希】
/// 遍历所有string，对string内的所有字母计数
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};