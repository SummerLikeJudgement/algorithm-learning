// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

// 示例 1：


// 输入：n = 4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释：如上图所示，4 皇后问题存在两个不同的解法。
// 示例 2：

// 输入：n = 1
// 输出：[["Q"]]
 

// 提示：

// 1 <= n <= 9


/// 【dfs】经典利用回溯问题，注意利用col、dig1、dig2剪枝（dig1、dig2下标要为正）
class Solution {
public:
    int N;
    vector<vector<string>> ans;
    // 棋盘结果
    int path[10][10];
    // 每列是否被使用
    bool col[10];
    // 两个对角线是否被使用
    bool dig1[20]; // 左上到右下
    bool dig2[20]; // 
    // 第u行的dfs（从0开始）
    void dfs(int u)
    {
        // 放置完成
        if(u == N)
        {
            vector<string> t;
            for(int i=0 ; i<N ; i++)
            {
                string s;
                for(int j=0 ; j<N ; j++)
                {
                    if(path[i][j] == 1)
                        s += 'Q';
                    else
                        s += '.';
                }
                t.push_back(s);
            }
            ans.push_back(t);
        }
        else
        {
            for(int i=0 ; i<N ; i++)
            {
                if(col[i] || dig1[u-i+N] || dig2[2*N-i-u])
                    continue;
                col[i] = true;
                dig1[u-i+N] = true;
                dig2[2*N-i-u] = true;
                path[u][i] = 1;
                dfs(u+1);
                // 恢复
                col[i] = false;
                dig1[u-i+N] = false;
                dig2[2*N-i-u] = false;
                path[u][i] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        dfs(0);
        return ans;
    }
};