// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

 

// 示例 1：

// 输入：grid = [
//   ['1','1','1','1','0'],
//   ['1','1','0','1','0'],
//   ['1','1','0','0','0'],
//   ['0','0','0','0','0']
// ]
// 输出：1
// 示例 2：

// 输入：grid = [
//   ['1','1','0','0','0'],
//   ['1','1','0','0','0'],
//   ['0','0','1','0','0'],
//   ['0','0','0','1','1']
// ]
// 输出：3
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] 的值为 '0' 或 '1'


/// 【dfs】
class Solution {
public:
    // bias
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    // (x,y)'s DFS
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        grid[x][y] = '0';

        for(int i=0 ; i<4 ; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx<0 || tx>=grid.size())
                continue;
            if(ty<0 || ty>=grid[tx].size())
                continue;
            if(grid[tx][ty] == '1')
            {
                dfs(tx, ty, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i=0 ; i<grid.size() ; i++)
            for(int j=0 ; j<grid[i].size() ; j++)
                if(grid[i][j] == '1' )
                {
                    dfs(i, j, grid);
                    ans++;
                }

        return ans;
    }
};
/// 优化：tx、ty可不用循环