//洛谷KMP模板题https://www.luogu.com.cn/problem/P3375

// ## 题目描述

// 给出两个字符串 $s_1$ 和 $s_2$，若 $s_1$ 的区间 $[l, r]$ 子串与 $s_2$ 完全相同，则称 $s_2$ 在 $s_1$ 中出现了，其出现位置为 $l$。  
// 现在请你求出 $s_2$ 在 $s_1$ 中所有出现的位置。

// 定义一个字符串 $s$ 的 border 为 $s$ 的一个**非 $s$ 本身**的子串 $t$，满足 $t$ 既是 $s$ 的前缀，又是 $s$ 的后缀。  
// 对于 $s_2$，你还需要求出对于其每个前缀 $s'$ 的最长 border $t'$ 的长度。

// ## 输入格式

// 第一行为一个字符串，即为 $s_1$。  
// 第二行为一个字符串，即为 $s_2$。

// ## 输出格式

// 首先输出若干行，每行一个整数，**按从小到大的顺序**输出 $s_2$ 在 $s_1$ 中出现的位置。  
// 最后一行输出 $|s_2|$ 个整数，第 $i$ 个整数表示 $s_2$ 的长度为 $i$ 的前缀的最长 border 长度。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// ABABABC
// ABA

// ```

// ### 输出 #1

// ```
// 1
// 3
// 0 0 1 

// ```

// ## 说明/提示

// ### 样例 1 解释
// 对于 $s_2$ 长度为 $3$ 的前缀 `ABA`，字符串 `A` 既是其后缀也是其前缀，且是最长的，因此最长 border 长度为 $1$。


// ### 数据规模与约定

// **本题采用多测试点捆绑测试，共有 4 个子任务**。

// - Subtask 0（30 points）：$|s_1| \leq 15$，$|s_2| \leq 5$。
// - Subtask 1（40 points）：$|s_1| \leq 10^4$，$|s_2| \leq 10^2$。
// - Subtask 2（30 points）：无特殊约定。
// - Subtask 3（0 points）：Hack。

// 对于全部的测试点，保证 $1 \leq |s_1|,|s_2| \leq 10^6$，$s_1, s_2$ 中均只含大写英文字母。

#include <iostream>

using namespace std;

const int N=1e6+10;

// char s1[N], s2[N];//s1>s2
string s1, s2;
int ne[N];

int main()
{
    cin >> s1 >> s2;
    s1 = "0"+s1;
    s2 = "0"+s2;

    int m=s1.size()-1, n=s2.size()-1;
    //求next数组
    for (int i=2, j=0 ; i<=n ; i++)
    {
        while(j && s2[i]!=s2[j+1])
            j=ne[j];
        if(s2[i]==s2[j+1])
            j++;
        ne[i]=j;
        // printf("ne[%d]=%d\n", i, ne[i]);
    }
    
    for (int i=1, j=0 ; i<=m ; i++)
    {
        while(j && s1[i]!=s2[j+1])
            j=ne[j];
        if(s1[i]==s2[j+1])
            j++;
        if(j==n)
        {
            printf("%d\n", i-n+1);
            j=ne[j];
        }
    }

    for (int i=1 ; i<=n ; i++)
        printf("%d ",ne[i]);

    return 0;
}