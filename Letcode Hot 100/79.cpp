// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

// 示例 1：


// 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCCED"
// 输出：true
// 示例 2：


// 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "SEE"
// 输出：true
// 示例 3：


// 输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCB"
// 输出：false
 

// 提示：

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board 和 word 仅由大小写英文字母组成
 

// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？

/// 【dfs+回溯】典型dfs问题
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int cnt)
    {
        if(cnt == word.size())
            return true;
        for(int k=0 ; k<4 ; k++)
        {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx<0 || tx>=board.size() || ty<0 || ty>=board[0].size())
                continue;
            if(board[tx][ty] == word[cnt])
            {
                char temp = board[tx][ty];
                board[tx][ty] = '0';
                if(dfs(board, word, tx, ty, cnt+1))
                    return true;
                board[tx][ty] = temp;
            }

        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();


        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<n ; j++)
            {
                if(board[i][j] == word[0])
                {
                    char temp = board[i][j];
                    board[i][j] = '0';
                    if(dfs(board, word, i, j, 1))
                        return true;
                    board[i][j] = temp;
                }
            }
        return false;
                
    }
};