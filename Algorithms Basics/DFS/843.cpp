// 题目描述
// n− 皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。
// 现在给定整数 n，请你输出所有的满足条件的棋子摆法。

// 输入格式
// 共一行，包含整数 n。

// 输出格式
// 每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。
// 其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。
// 每个方案输出完成后，输出一个空行。

// 注意：行末不能有多余空格。

// 输出方案的顺序任意，只要不重复且没有遗漏即可。

// 输入输出样例
// 输入
// 4

// 输出
// .Q..
// ...Q
// Q...
// ..Q.

// ..Q.
// Q...
// ...Q
// .Q..

// 说明/提示
// 数据范围 1≤n≤9


//// 按每行来DFS（每行只有一个皇后）
// #include <iostream>

// using namespace std;

// const int N=10;

// int n;
// int path[N][N];
// bool col[N];// 列是否已经被使用
// bool dg[2*N], udg[2*N]; // 正反对角线是否已经被使用，通过截距标记各对角线
// // 第u行的dfs
// void dfs(int u)
// {
//     if(u == n)
//     {
//         for(int i=0 ; i<n ; i++)
//         {
//             for(int j=0 ; j<n ; j++)
//             {
//                 if(path[i][j] == 1) printf("Q");
//                 else printf(".");
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
//     else
//     {
//         for(int i=0 ; i<n ; i++)
//         {
//             if(!col[i] && !dg[u+n-i] && !udg[u+i])// 列、对角线、反对角线都未使用
//             {
//                 path[u][i] = 1;
//                 col[i] = true;
//                 dg[u+n-i] = true;
//                 udg[u+i] = true;
//                 //下一层dfs
//                 dfs(u+1);
//                 //回溯
//                 path[u][i] = 0;
//                 col[i] = false;
//                 dg[u+n-i] = false;
//                 udg[u+i] = false;
//             }
//         }
//     }
// }

// int main()
// {
//     scanf("%d", &n);

//     dfs(0);

//     return 0;
// }


//// 按每格来DFS
#include <iostream>

using namespace std;

const int N=10;

int n;
char g[N][N];
bool col[N], row[N];// 列是否已经被使用
bool dg[2*N], udg[2*N]; // 正反对角线是否已经被使用，通过截距标记各对角线


// 第x行、第y列的dfs
void dfs(int x, int y, int s)// s代表已经放置的皇后个数
{
   //超出位置则下一行
   if(y == n)
   {
        y = 0;
        x++;
   }

   if (x == n) // 已经遍历完所有行（x == n 表示越界）
   {
        // 如果放置完成
        if (s == n)
        {
            for (int i=0 ; i<n ; i++) puts(g[i]);
            puts("");
        }
        return;
   }

   // 不放皇后
   dfs(x, y+1, s);
   // 放皇后
   if(!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n])
   {
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = true;
        g[x][y] = 'Q';
        // 下一格DFS
        dfs(x, y+1, s+1);
        // 回溯
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = false;
        g[x][y] = '.';
   }
   return;
}

int main()
{
    scanf("%d", &n);
    for (int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            g[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}
