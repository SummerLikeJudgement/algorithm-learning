// 题目描述
// 按照字典序输出自然数 1 到 n 所有不重复的排列，即 n 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

// 输入格式
// 一个整数 n。

// 输出格式
// 由 1∼n 组成的所有不重复的数字序列，每行一个序列。

// 每个数字保留 5 个场宽。

// 输入输出样例
// 输入
// 3

// 输出
//     1    2    3
//     1    3    2
//     2    1    3
//     2    3    1
//     3    1    2
//     3    2    1
// 说明/提示
// 1≤n≤9。

#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N]; // 当前的数字顺序
bool st[N]; // 存储哪些数字已经被使用了

// 在第u个位置的dfs
void dfs(int u)
{
    if(u == n)
    {
        for (int i=0 ; i<n ; i++) 
            printf("    %d", path[i]);
        printf("\n");
    }
            
    else // u<n
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(!st[i])
            {
                path[u] = i;
                st[i] = true;
                // dfs下一层
                dfs(u + 1);
                // 下一层处理结束后要回溯（恢复现场）
                st[i] = false; // 因为u没有改变，所以path不需要显式回溯
            }
        }
    }

    return;
}

int main()
{
    scanf("%d", &n);
    //从0层开始dfs
    dfs(0);

    return 0;
}