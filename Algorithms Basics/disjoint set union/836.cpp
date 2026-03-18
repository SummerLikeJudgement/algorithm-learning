// 题目描述
// 一共有 𝑛 个数，编号是 1∼𝑛，最开始每个数各自在一个集合中。
// 现在要进行 𝑚 个操作，操作共有两种：

// M a b，将编号为 𝑎 和 𝑏 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
// Q a b，询问编号为 𝑎 和 𝑏 的两个数是否在同一个集合中；

// 输入格式
// 第一行输入整数 𝑛 和 𝑚。
// 接下来 𝑚 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。
// 输出格式
// 对于每个询问指令 Q a b，都要输出一个结果，如果 𝑎 和 𝑏 在同一集合内，则输出 Yes，否则输出 No。
// 每个结果占一行。
// 数据范围
// 1≤𝑛,𝑚≤10^5
// 输入样例：
// 4 5
// M 1 2
// M 3 4
// Q 1 2
// Q 1 3
// Q 3 4

// 输出样例：
// Yes
// No
// Yes

#include <iostream>

using namespace std;

const int N=1e5+10;

int p[N];// 存储每个编号的父节点

//返回编号x的祖宗节点+路径压缩
int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    //初始化，每个元素分别在一个树
    for(int i=1 ; i<=n ; i++)
        p[i] = i;

    while(m--)
    {
        char Oper[2];
        int a, b;
        scanf("%s%d%d", &Oper, &a, &b);

        if (Oper[0] == 'M')// 合并集合
            p[find(a)] = find(b); // 使a的祖宗节点成为b的子节点
        else// 询问集合
        {
            if(find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

}