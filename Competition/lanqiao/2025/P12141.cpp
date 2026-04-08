// # P12141 [蓝桥杯 2025 省 A] 红黑树

// ## 题目描述

// 小蓝最近学习了红黑树，红黑树是一种特殊的二叉树，树上的结点有两种类型：红色结点和黑色结点。  

// 小蓝在脑海中构造出一棵红黑树，构造方式如下：  

// 1. 根结点是一个红色结点；  
// 2. 如果当前结点 $\rm curNode$ 是红色结点，那么左子结点 $\rm curNode.left$ 是红色结点，右子结点 $\rm curNode.right$ 是黑色结点；  
// 3. 如果当前结点 $\rm curNode$ 是黑色结点，那么左子结点 $\rm curNode.left$ 是黑色结点，右子结点 $\rm curNode.right$ 是红色结点；  

// 此二叉树前几层的形态如下图所示：  

// ![](https://cdn.luogu.com.cn/upload/image_hosting/rc6o7xe8.png)

// 小蓝会从树上随机挑选结点，请你帮忙判断他选出的是红色结点还是黑色结点。

// ## 输入格式

// 输入的第一行包含一个正整数 $m$，表示小蓝挑选的结点数。

// 接下来 $m$ 行，每行包含两个正整数 $n_i, k_i$，用一个空格分隔，表示小蓝挑选的结点是第 $n_i$ 行（从上往下数）第 $k_i$ 个（从左往右数）结点。

// ## 输出格式

// 输出 $m$ 行，每行包含一个字符串，依次表示小蓝每次挑选的结点的答案。`RED` 表示红色结点，`BLACK` 表示黑色结点。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 2
// 1 1
// 2 2
// ```

// ### 输出 #1

// ```
// RED
// BLACK
// ```

// ## 说明/提示

// ### 样例说明
// - 第一行第一个结点为根结点，红色；
// - 第二行第二个结点为黑色结点。

// ### 评测用例规模与约定

// - 对于 $20\%$ 的评测用例，$1 \leq m \leq 5$，$1 \leq n_i \leq 5$；
// - 对于 $40\%$ 的评测用例，$1 \leq m \leq 10$，$1 \leq n_i \leq 5$；
// - 对于 $60\%$ 的评测用例，$1 \leq m \leq 5$，$1 \leq n_i \leq 10$；
// - 对于 $80\%$ 的评测用例，$1 \leq m \leq 10$，$1 \leq n_i \leq 15$；
// - 对于所有评测用例，$1 \leq m \leq 10$，$1 \leq n_i \leq 30$，$1 \leq k_i \leq 2^{n_i-1}$。


/// 本质思想：默认询问结点是红色，根据性质找到根结点颜色，如果红色则成立，如果黑色则矛盾（询问结点是黑色）
// #include <iostream>
// #include <cmath>

// using namespace std;

// int m;

// string check(int pos)
// {
//     bool flag = true;// 默认结点是红色
//     while (pos != 1)
//     {
//         if(pos%2 == 0) // 左子结点
//         {
//             // 父节点颜色和左子节点相同
//             pos = pos / 2;
//         }
//         else // 右子节点
//         {
//             // 父节点颜色和右子节点不同
//             if(flag)
//                 flag = false;
//             else 
//                 flag = true;
//             pos = pos / 2;
//         }
//     }
//     if(flag == true)
//         return "RED";
//     else
//         return "BLACK";
// }

// int main()
// {
//     scanf("%d", &m);
//     while (m--)
//     {
//         int n, k;
//         scanf("%d%d", &n, &k);
//         int pos = pow(2, n-1)-1+k;
//         string ans = check(pos);
//         cout << ans << endl;
//     }

//     return 0;
// }

/// 本质思想：根节点总是和其左儿子颜色相同，右儿子颜色相反。可以通过从根节点到一个子节点的路径（即向右走的次数）来判断该子结点的颜色。
///         用 0 表示向左走，1 表示向右走，这样就可以使用一个二进制数来将完整的路径表示出来，容易发现这个数就是 k−1。于是统计 k−1 的二进制表示中 1 的个数，偶数则该节点为红色，奇数则该节点为黑色。

#include <iostream>

using namespace std;

int main()
{
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        // 使用__builtin_popcountll计算1的个数
        // if(__builtin_popcountll(k-1) % 2)//1的个数是奇数
        //     printf("BLACK\n");
        // else
        //     printf("RED\n");

        // 使用lowbit计算1的个数
        int cnt = 0;
        k = k-1;
        while(k)
        {
            int x = k & -k;
            k -= x;
            cnt++;
        }
        if(cnt % 2)
            printf("BLACK\n");
        else
            printf("RED\n");
    }
    return 0;
}