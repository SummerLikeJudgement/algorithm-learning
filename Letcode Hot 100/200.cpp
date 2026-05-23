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


/// 【BFS】
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // bias
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        // queue
        queue<pair<int, int>> q;

        int ans = 0;
        
        for(int i=0 ; i<grid.size() ; i++)
            for(int j=0 ; j<grid[i].size() ; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    q.push({i,j});
                    // bfs
                    while(q.size())
                    {
                        auto t = q.front();
                        q.pop();
                        for(int k=0 ; k<4 ; k++)
                        {
                            int x = t.first + dx[k];
                            int y = t.second + dy[k];
                            if(x>=0  && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y]=='1')
                            {
                                grid[x][y] = '0';
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        return ans;
    }
};


/// 【并查集（按秩合并）】只能按秩合并
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};