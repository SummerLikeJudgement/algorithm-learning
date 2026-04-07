// 来自洛谷 稍微扩展acwing282石子合并的模板题：https://www.luogu.com.cn/problem/P1880

// # P1880 [NOI1995] 石子合并

// ## 题目描述

// 在一个圆形操场的四周摆放 $N$ 堆石子，现要将石子有次序地合并成一堆，规定每次只能选相邻的 $2$ 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。

// 试设计出一个算法，计算出将 $N$ 堆石子合并成 $1$ 堆的最小得分和最大得分。

// ## 输入格式

// 数据的第 $1$ 行是正整数 $N$，表示有 $N$ 堆石子。

// 第 $2$ 行有 $N$ 个整数，第 $i$ 个整数 $a_i$ 表示第 $i$ 堆石子的个数。

// ## 输出格式

// 输出共 $2$ 行，第 $1$ 行为最小得分，第 $2$ 行为最大得分。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 4
// 4 5 9 4
// ```

// ### 输出 #1

// ```
// 43
// 54
// ```

// ## 说明/提示

// $1\leq N\leq 100$，$0\leq a_i\leq 20$。


/// 直接处理环形边界
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N=110;
// // 石子的前缀和数组
// int s[N];
// int f_max[N][N];
// int f_min[N][N];

// int n;


// int main()
// {
//     scanf("%d", &n);
//     for(int i=1 ; i<=n ; i++)
//     {
//         scanf("%d", &s[i]);
//         s[i] += s[i-1];
//     }
//     // 初始化f
//     memset(f_min, 0x3f, sizeof f_min);
//     for(int i=1 ; i<=n ; i++)
//         f_min[i][i] = 0;

//     int min_ans = 0x3f3f3f3f;
//     int max_ans = 0;

//     // 最小代价
//     for(int len=2 ; len<=n ; len++)
//     {
//         for(int i=1 ; i<=n ; i++)
//         {
//             int j=i+len-1; // j可能大于n即回到初始
//             for(int k=i ; k+1<=j ; k++)
//             {
//                 int m; // 最后合并的代价
//                 if(j > n) // j回到初始
//                 {
//                     m = s[n]-s[i-1] + s[j%n]- s[0];
//                     int f1_min, f2_min;
//                     int f1_max, f2_max;
//                     if(k+1 > n) 
//                     {
//                         f2_min = f_min[(k+1)%n][j%n];
//                         f2_max = f_max[(k+1)%n][j%n];
//                     }
//                     else 
//                     {
//                         f2_min = f_min[k+1][j%n];
//                         f2_max = f_max[k+1][j%n];
//                     }
//                     if(k>n)
//                     {
//                         f1_min = f_min[i][k%n];
//                         f1_max = f_max[i][k%n];
//                     }
//                     else
//                     {
//                         f1_min = f_min[i][k];
//                         f1_max = f_max[i][k];
//                     }
                        

//                     f_min[i][j%n] = min(f_min[i][j%n], f1_min + f2_min + m);
//                     f_max[i][j%n] = max(f_max[i][j%n], f1_max + f2_max + m);
//                     // printf("\nf1=%d, f2=%d\n", f1, f2);

//                     if(len == n)
//                     {
//                         min_ans = min(min_ans, f_min[i][j%n]);
//                         max_ans = max(max_ans, f_max[i][j%n]);
//                     }
//                 }
//                 else // j未回到初始
//                 {
//                     m = s[j] - s[i-1];
//                     f_min[i][j] = min(f_min[i][j], f_min[i][k] + f_min[k+1][j] + m);
//                     f_max[i][j] = max(f_max[i][j], f_max[i][k] + f_max[k+1][j] + m);

//                     if(len == n)
//                     {
//                         min_ans = min(min_ans, f_min[i][j]);
//                         max_ans = max(max_ans, f_max[i][j]);
//                     }
//                 }
                
//             }
            
//             // if(j>n)
//             //     printf("\nf(%d, %d) = %d\n",i, j%n, f_min[i][j%n]);
//             // else
//             //     printf("\nf(%d, %d) = %d\n",i, j, f_min[i][j]);
//         }
//     }


//     printf("%d\n%d",min_ans, max_ans);

//     return 0;
// }



/// 将两个链拼接，等价于环
#include <iostream>
#include <cstring>

using namespace std;

const int N=210;
// 石子的前缀和数组
int s[N];
int v[N];
int f_max[N][N];
int f_min[N][N];

int n;


int main()
{
    scanf("%d", &n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d", &v[i]);
        s[i] = s[i-1] + v[i];
    }
    for(int i=n+1 ; i<=2*n ; i++)
        s[i] = s[i-1] + v[i-n];
    // 初始化f
    memset(f_min, 0x3f, sizeof f_min);
    for(int i=1 ; i<=2*n ; i++)
        f_min[i][i] = 0;

    int min_ans = 0x3f3f3f3f;
    int max_ans = 0;

    // 最小代价
    for(int len=2 ; len<=n ; len++)
    {
        for(int i=1 ; i<=2*n+1-len ; i++)
        {
            int j=i+len-1; // j可能大于n即回到初始
            for(int k=i ; k+1<=j ; k++)
            {
                int m = s[j] - s[i-1];; // 最后合并的代价
                f_min[i][j] = min(f_min[i][j], f_min[i][k] + f_min[k+1][j] + m);
                f_max[i][j] = max(f_max[i][j], f_max[i][k] + f_max[k+1][j] + m);

                if(len == n)
                {
                    min_ans = min(min_ans, f_min[i][j]);
                    max_ans = max(max_ans, f_max[i][j]);
                }
            }
            
            // if(j>n)
            //     printf("\nf(%d, %d) = %d\n",i, j%n, f_min[i][j%n]);
            // else
            //     printf("\nf(%d, %d) = %d\n",i, j, f_min[i][j]);
        }
    }


    printf("%d\n%d",min_ans, max_ans);

    return 0;
}
