// 题目背景
// 在某个科学实验室中，有一组编号为 (1∼n) 的研究节点，初始时，这些节点之间没有任何连接。实验需要对这些节点进行动态操作并回答相关查询。实验设计如下：

// 题目描述
// 实验需要支持以下三种操作：

// 添加边操作
// 格式：C a b
// 在节点 (a) 和节点 (b) 之间建立一条边（(a) 和 (b) 可以相同）。

// 连通性查询操作
// 格式：Q1 a b
// 判断节点 (a) 和节点 (b) 是否在同一个连通块中，输出 Yes 或 No。

// 连通块大小查询操作
// 格式：Q2 a
// 查询节点 (a) 所在连通块中节点的数量。

// 输入格式
// 第一行输入两个整数 (n) 和 (m)，分别表示节点数量和操作数量。
// 接下来的 (m) 行，每行包含一个操作，操作类型为 C a b、Q1 a b 或 Q2 a。
// 输出格式
// 对于每个 Q1 a b 操作，输出 Yes 或 No。
// 对于每个 Q2 a 操作，输出一个整数，表示连通块的节点数量。
// 每个结果占一行。

// 输入输出样例
// 输入
// 5 5
// C 1 2
// Q1 1 2
// Q2 1
// C 2 5
// Q2 5

// 输出
// Yes
// 2
// 3

// 说明/提示
// (1≤n,m≤10^5)

#include <iostream>

using namespace std;

const int N = 1e5+10;
int p[N];
int s[N];

int find(int x)
{
    if (p[x]!=x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    //初始化
    for (int i=1 ; i<=n ; i++)
        p[i] = i, s[i] = 1;
    
    while(m--)
    {
        char Op[3];
        scanf("%s", Op);
        if (Op[0] == 'C')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) != find(b)) 
                s[find(b)] += s[find(a)];
            p[find(a)] = find(b);
        }
        else if(Op[1] == '1')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            int a;
            scanf("%d", &a);
            printf("%d\n", s[find(a)]);
        }
    }

    return 0;
}