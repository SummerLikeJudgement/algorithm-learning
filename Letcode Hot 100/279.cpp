// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

 

// 示例 1：

// 输入：n = 12
// 输出：3 
// 解释：12 = 4 + 4 + 4
// 示例 2：

// 输入：n = 13
// 输出：2
// 解释：13 = 4 + 9
 
// 提示：

// 1 <= n <= 104


/// 【动态规划】相当于完全背包问题：从1~i（i*i<=n）中选择数字，使得平方和为n的最小数字个数
/// f[i][j]：表示从[1,i]中选择，平方和为j的所有方案的最小个数
/// f[i][j] = min(f[i-1][j], f[i-1][j-k*i*i]+k)
/// 完全背包的经典优化思路可得：f[j] = min(f[j], f[j-i*i]+1)
const int N = 10005;
int f[N];
class Solution {
public:
    int numSquares(int n) {
        // init
        int maxn = 1;
        while(maxn*maxn <= n)// 找到最大的完全平方数
        {maxn ++;}
        for(int i=0 ; i<=n ; i++)
            f[i] = INT_MAX;// MAX代表找不到
        f[0] = 0; // f[i][0]=0;f[0][i]=MAX;;f[0][0]=MAX
        maxn --;
        for(int i=1 ; i<=maxn ; i++)
            for(int j=i*i ; j<=n ; j++)
                f[j] = min(f[j], f[j-i*i]+1);
        return f[n];
    }
};


/// 【数学】四平方和定理：任意一个正整数都可以被表示为至多四个正整数的平方和。
/// 当且仅当n!=4^k*(8m+7)时，n可以被表示为至多三个正整数的平方和。
/// 故n==4^k*(8m+7)时，n只能表示为四个正整数的平方和，直接返回 4；
/// n!=4^k*(8m+7)时，只能为1（n==a*a）/2（n==a*a+b*b）/3（排除1/2）
class Solution {
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3; //不是1/2
    }
};