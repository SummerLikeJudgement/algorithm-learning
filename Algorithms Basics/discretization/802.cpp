// 假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。
// 现在，我们首先进行 n次操作，每次操作将某一位置 x上的数加 c。
// 接下来，进行 m次询问，每个询问包含两个整数 l 和 r ，你需要求出在区间 [l,r]之间的所有数的和。

// 输入格式
// 第一行包含两个整数 n 和 m。
// 接下来 n 行，每行包含两个整数 x 和 c 。
// 再接下来 m 行，每行包含两个整数 l 和 r 。

// 输出格式
// 共 m 行，每行输出一个询问中所求的区间内数字和。

// 数据范围
// -10^9≤x≤10^9,
// 1≤n,m≤10^5,
// -10^9≤l≤r≤10^9,
// -10000≤c≤10000

// 输入样例
// 3 3
// 1 2
// 3 6
// 7 5
// 1 3
// 4 6
// 7 8
// 输出样例
// 8
// 0
// 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 +10;
int a[N], S[N]; //离散化映射后的数组， 前缀和数组 
vector<int> alls; //存储所有待离散化数
vector<PII> add, query;// 存储n次增加操作；m次询问操作

// 找到x离散化映射的值
int find(int x)
{
    int l = 0, r = alls.size()-1;
    while(l<r)
    {
        int mid = l+r+1 >> 1;
        if (alls[mid] <= x) l = mid;
        else r = mid-1;
    }
    return l+1;// 将alls映射到从1开始的数字（要用到前缀和）
}

int main()
{
    int n, m;
    scanf("%d%d",&n ,&m);

    for (int i=0 ; i<n ; i++)
    {
        int x, c;
        scanf("%d%d",&x, &c);
        add.push_back({x, c});

        alls.push_back(x);
    }

    for (int i=0 ; i<m ; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        // 询问的数值也要加入待离散化集合中
        alls.push_back(l);
        alls.push_back(r);
    }
    // 离散化
    sort(alls.begin(), alls.end());// 先排序再去重
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // for (int i=0 ; i<alls.size() ; i++) printf("%d ",alls[i]);
    // printf("\n");

    for (auto item : add)
    {
        int x = find(item.first);
        // printf("%d ", x);
        a[x] += item.second;
    }
    // printf("\n");
    // 计算前缀和数组
    for (int i=1 ; i<=alls.size() ; i++)
    {
        S[i] = S[i-1]+a[i];
    }
    // 回答询问
    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        printf("%d\n",S[r]-S[l-1]);
    }

    return 0;
}