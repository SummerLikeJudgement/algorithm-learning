// 有N种物品和一个容量是V的背包，每种物品都有无限件可用。
// 第i种物品的体积是vi，价值是wi。
// 求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
// 输出最大价值。

// 输入格式
// 第一行两个整数N，V，用空格隔开，分别表示物品种数和背包容积。
// 接下来有 N行，每行两个整数vi,wi，用空格隔开，分别表示第 i种物品的体积和价值。

// 输出格式
// 输出一个整数，表示最大价值。

// 数据范围
// 0<N,V≤1000
// 0<vi,wi≤1000

// 输入样例
// 4 5
// 1 2
// 2 4
// 3 4
// 4 5
// 输出样例：
// 10



/// 初始状态
// #include <iostream>

// using namespace std;

// const int M = 1010;

// int N, V;
// int v[M], w[M];
// int f[M][M];

// int main()
// {
//     scanf("%d%d", &N, &V);
//     for(int i=1 ; i<=N ; i++)
//         scanf("%d%d", &v[i], &w[i]);
//     // 初始化f(0, 1~V)=0

//     for(int i=1 ; i<=N ; i++)
//         for(int j=1 ; j<=V ; j++)
//             for(int k=0 ; k*v[i]<=j ; k++)
//                 f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i]);

//     printf("%d", f[N][V]);

//     return 0;
// }

/// 对三重循环进行优化，k的循环可以简化
/// f(i,j) = max(f(i-1,j),f(i-1,j-v)+w,f(i-1,j-2v)+2w,...)
/// f(i,j-v) =        max(f(i-1,j-v),f(i-1,j-2v)+w,...)
/// 即f(i,j)=max(f(i-1,j), f(i-1,j-v)+w)，注意j<v时，f(i-1,j-v)可能不存在
// #include <iostream>

// using namespace std;

// const int M = 1010;

// int N, V;
// int v[M], w[M];
// int f[M][M];

// int main()
// {
//     scanf("%d%d", &N, &V);
//     for(int i=1 ; i<=N ; i++)
//         scanf("%d%d", &v[i], &w[i]);
//     // 初始化f(0, 1~V)=0

//     for(int i=1 ; i<=N ; i++)
//         for(int j=0 ; j<=V ; j++)
//         {
//             f[i][j] = f[i-1][j];
//             if(j>=v[i]) f[i][j] = max(f[i][j], f[i][j-v[i]]+w[i]);
//         }
            

//     printf("%d", f[N][V]);

//     return 0;
// }

/// 对二重循环进行优化，用一维状态
#include <iostream>

using namespace std;

const int M = 1010;

int N, V;
int v[M], w[M];
int f[M];

int main()
{
    scanf("%d%d", &N, &V);
    for(int i=1 ; i<=N ; i++)
        scanf("%d%d", &v[i], &w[i]);
    // 初始化f(1~V)=0

    for(int i=1 ; i<=N ; i++)
        for(int j=v[i] ; j<=V ; j++)
            f[j] = max(f[j], f[j-v[i]]+w[i]);
            

    printf("%d", f[V]);

    return 0;
}