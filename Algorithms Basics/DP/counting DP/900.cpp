// 题目描述
// 一个正整数 
// n
//  可以表示成若干个正整数之和，形如：
// n
// =
// n
// 1
// +
// n
// 2
// +
// …
// +
// n
// k
// ，其中 
// n
// 1
// ≥
// n
// 2
// ≥
// …
// ≥
// n
// k
// ,
// k
// ≥
// 1
// 。

// 我们将这样的一种表示称为正整数 
// n
//  的一种划分。

// 现在给定一个正整数 
// n
// ，请你求出 
// n
//  共有多少种不同的划分方法。

// 输入格式
// 共一行，包含一个整数 
// n
// 。

// 输出格式
// 共一行，包含一个整数，表示总划分数量。

// 由于答案可能很大，输出结果请对 
// 10
// 9
// +
// 7
//  取模。

// 数据范围
// 1
// ≤
// n
// ≤
// 1000

// 输入样例:

// 5
// 输出样例：

// 7



//// 完全背包问题
/// 把整数n看成一个容量为n的背包，有n种物品，物品的体积分别是1~n,要求的是 恰好 装满背包的方案数(计数)，每种物品 可以用无限次，所以可以看成是一个完全背包

/// 二维f(i,j)，前i个物品中选+体积恰好为j的所有方案的个数

// #include <iostream>

// using namespace std;

// const int N = 2000;
// const int M = 1e9+7;

// int f[N][N];
// int n;

// int main()
// {
//     // 初始化f
//     for(int i=0 ; i<N ; i++)
//         f[i][0] = 1;

//     scanf("%d", &n);

//     for(int i=1 ; i<=n ; i++)
//         for(int j=1 ; j<=n ; j++)
//         {
//             f[i][j] = (f[i][j] + f[i-1][j]) % M; // 选0个i
//             for(int m=1 ; m*i<=j ; m++) // 选m个i
//             {
//                 f[i][j] = (f[i][j] + f[i-1][j-m*i]) % M;
//             }
//             // printf("f(%d,%d)=%d\n", i, j, f[i][j]);
//         }
    
//     printf("%d", f[n][n]);

//     return 0;
// }


/// 一维
// #include <iostream>

// using namespace std;

// const int N = 2000;
// const int M = 1e9+7;

// int f[N];
// int n;

// int main()
// {
//     // 初始化f
//     f[0] = 1;

//     scanf("%d", &n);

//     for(int i=1 ; i<=n ; i++)
//         for(int j=1 ; j<=n ; j++) // 从小到大遍历
//             f[j] = (f[j] + f[j-i]) % M; // 完全背包经典优化：据观察f[i][j] = f[i-1][j] + f[i][j-i];
    
//     printf("%d", f[n]);

//     return 0;
// }


//// 
/// 二维f(i,j)：所有总和是i+恰好表示成j个数的和的方案的个数
/// 状态转换：最小值是1的方案（去掉一个数字1）+最小值大于1的方案（所有数字减去1）
///     f(i,j) = f(i-1,j-1) + f(i-j,j)

#include <iostream>

using namespace std;

const int N = 2000;
const int M = 1e9+7;

int f[N][N];
int n;

int main()
{
    // 初始化f
    f[0][0] = 1;

    scanf("%d", &n);

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=i ; j++)
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % M;

    int ans = 0;

    for(int i=1 ; i<=n ; i++)
        ans = (ans+f[n][i]) % M;

    printf("%d", ans);

    return 0;
}