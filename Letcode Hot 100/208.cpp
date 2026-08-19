// Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

// 请你实现 Trie 类：

// Trie() 初始化前缀树对象。
// void insert(String word) 向前缀树中插入字符串 word 。
// boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
// boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

// 示例：

// 输入
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// 输出
// [null, null, true, false, true, null, true]

// 解释
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // 返回 True
// trie.search("app");     // 返回 False
// trie.startsWith("app"); // 返回 True
// trie.insert("app");
// trie.search("app");     // 返回 True
 

// 提示：

// 1 <= word.length, prefix.length <= 2000
// word 和 prefix 仅由小写英文字母组成
// insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次


/// 【Trie】使用数组实现Trie，注意N表示结点容量
const int N = 	100000;
const int M = 26;
const int C = M*N;

class Trie {
public:
    int son[N][M];
    int cnt[C];
    int idx = 0;
    Trie() {
        memset(son, 0 , sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
    }
    
    void insert(string word) {
        int p = 0;
        for(int i=0 ; word[i] ; i++)
        {
            int t = word[i] - 'a';
            // 还没有子节点
            if(!son[p][t])
                son[p][t] = ++idx;
            p = son[p][t];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p = 0;
        for(int i=0 ; word[i] ; i++)
        {
            int t = word[i] - 'a';
            // 没有子节点
            if(!son[p][t])
                return false;
            else
                p = son[p][t];
        }
        if(cnt[p])
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        int p = 0;      
        for(int i=0 ; prefix[i] ; i++)
        {
            int t = prefix[i] - 'a';
            // 没有子节点
            if(!son[p][t])
                return false;
            else
                p = son[p][t];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */