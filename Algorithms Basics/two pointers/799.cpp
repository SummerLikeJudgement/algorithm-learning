// 题目描述
// 给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

// 输入格式
// 第一行包含整数n
// 第二行包含 n 个整数（均在 0∼10^5范围内），表示整数序列。

// 输出格式
// 共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

// 输入输出样例
// 输入
// 5
// 1 2 2 3 5
// 输出
// 3

// 说明/提示
// 1≤n≤10^5

// #include <iostream>

// using namespace std;

// const int N = 100010;

// int S[N], a[N];// S是桶，用于记录个数。如果数字范围特别大，可以用hash表计数

// int main()
// {
//     int n;
//     scanf("%d",&n);

//     for (int i=0 ; i<n ; i++) scanf("%d",&a[i]);

//     int res = 0;

//     for (int i=0, j=0 ; i<n ; i++)
//     {
//         //维护[j,i]的窗口，这个窗口表示从i向左最远的不重复序列
//         S[a[i]]++;
//         while(S[a[i]] > 1)
//         {
//             S[a[j]]--;
//             j++;
//         }
//         res = max(res, i-j+1);
//     }

//     printf("%d",res);

//     return 0;
// }


/// 使用unordered_map作为hash表实现桶
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 100010;

int a[N];
unordered_map<int, int> S;// S是桶，用于记录出现个数

int main()
{
    int n;
    scanf("%d",&n);

    for (int i=0 ; i<n ; i++) scanf("%d",&a[i]);

    int res = 0;

    for(int i=0, j=0 ; i<n ; i++)
    {
        if(S.count(a[i]))
        {
            while (S.count(a[i]))
                S.erase(a[j++]);
        }
        S[a[i]] = 1;
        res = max(res, i-j+1);
    }

    printf("%d",res);

    return 0;
}