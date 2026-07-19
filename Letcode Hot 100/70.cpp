// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 

// 示例 1：

// 输入：n = 2
// 输出：2
// 解释：有两种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶
// 2. 2 阶
// 示例 2：

// 输入：n = 3
// 输出：3
// 解释：有三种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶 + 1 阶
// 2. 1 阶 + 2 阶
// 3. 2 阶 + 1 阶
 

// 提示：

// 1 <= n <= 45

/// 【动态规划】
const int N = 50;
class Solution {
public:
    int f[N];// 表示前i阶的所有方案的数量
    int climbStairs(int n) {
        f[0] = 1;
        f[1] = 1;
        for(int i=2 ; i<=n ; i++)
            f[i] = f[i-1] + f[i-2];\
        return f[n];
    }
};


/// 【数学】
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }
};