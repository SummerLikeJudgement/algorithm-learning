// 题目描述
// 有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
// 第 i 件物品的体积是 vi，价值是 wi。
// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。 输出最大价值。

// 输入格式
// 第一行两个整数，V，N，用空格隔开，分别表示背包容积和物品数量。
// 接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

// 输出格式
// 输出一个整数，表示最大价值。

// 输入输出样例
// 输入
// 5 4
// 1 2
// 2 4
// 3 4
// 4 5
// 输出
// 8

// 说明/提示
// 数据范围
// 0<N,V≤1000 0<vi,wi≤1000


/// 初始思路 二维表示状态
// #include <iostream>

// using namespace std;

// const int M = 1010;

// int V, N;
// int v[M], w[M];
// // 二维状态f(i,j)从前$i$个物品中选、总体积小于等于$j$的最大价值
// int f[M][M];

// int main()
// {
//     scanf("%d%d", &V, &N);
//     for(int i=1 ; i<=N ; i++)
//         scanf("%d%d", &v[i], &w[i]);
//     // 状态初始化:f(0,1~V)=0
//     // 计算每个状态
//     for(int i=1 ; i<=N ; i++)
//         for(int j=1 ; j<=V ; j++)
//         {
//             f[i][j] = f[i-1][j];
//             if(j>=v[i])
//                 f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]);
//         }
    
//     printf("%d", f[N][V]);

//     return 0;
// }


/// 对二重循环进行优化 用一维表示状态
#include <iostream>

using namespace std;

const int M = 1010;

int V, N;
int v[M], w[M];
// 第i件物品选择或不选择，都只和i-1的情况相关联
// 也就是说在i-1再以前的状态和数据与i无关，可以不用记录
int f[M];

int main()
{
    scanf("%d%d", &V, &N);
    for(int i=1 ; i<=N ; i++)
        scanf("%d%d", &v[i], &w[i]);
    // 状态初始化:f(0,1~V)=0
    // 计算每个状态
    for(int i=1 ; i<=N ; i++)
    // f[j]要依赖于原始的f[<j]即i-1层的结果
    // 如果j从小到大遍历，那么f[<j]会先于f[j]变化，使用到的是新结果
    // 而j从大到小遍历，f[j]会先于f[<j]变化，就不会出现问题了
        for(int j=V ; j>=v[i] ; j--)
            f[j] = max(f[j], f[j-v[i]]+w[i]);
    
    printf("%d", f[V]);

    return 0;
}