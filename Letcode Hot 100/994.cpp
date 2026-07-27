// 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

 

// 示例 1：



// 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
// 输出：4
// 示例 2：

// 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
// 输出：-1
// 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
// 示例 3：

// 输入：grid = [[0,2]]
// 输出：0
// 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] 仅为 0、1 或 2

/// 【bfs】这是多源bfs，本质上与普通单源bfs相同
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        for(int i=0 ; i<m ; i++)
            for(int j=0 ; j<n ; j++)
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
        
        while(q.size() && fresh)
        {
            int size_ = q.size();
            while(size_ --)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0 ; k<4 ; k++)
                {
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    if(tx<0 || tx>=m || ty<0 || ty>=n)
                        continue;
                    if(grid[tx][ty] != 1)
                        continue;
                    grid[tx][ty] = 2;
                    fresh--;
                    q.push({tx,ty});
                }
            }
            cnt++;
        }

        if(fresh)
            return -1;
        else
            return cnt;
    }
};