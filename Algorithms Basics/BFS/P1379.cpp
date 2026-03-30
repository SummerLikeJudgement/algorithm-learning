// 洛谷中类似于acwing 845的题目:https://www.luogu.com.cn/problem/P1379

// 题目描述
// 在 3×3 的棋盘上，摆有八个棋子，每个棋子上标有 1 至 8 的某一数字。棋盘中留有一个空格，空格用 0 来表示。空格周围的棋子可以移到空格中。要求解的问题是：给出一种初始布局（初始状态）和目标布局（为了使题目简单,设目标状态为 123804765），找到一种最少步骤的移动方法，实现从初始布局到目标布局的转变。

// 输入格式
// 输入初始状态，一行九个数字，空格用 0 表示。

// 输出格式
// 只有一行，该行只有一个数字，表示从初始状态到目标状态需要的最少移动次数。保证测试数据中无特殊无法到达目标状态数据。

// 输入输出样例
// 输入
// 283104765

// 输出 
// 4

// 说明/提示
// 样例解释
// 图中展示了样例当中从初始状态到目标状态的一种方案，共需要 4 步。
// 并且可以证明，不存在更优的策略。


#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

queue<string> q;
unordered_map<string, int> dist;// 键值对存储string和距离

string tar = "123804765";
string init;

void bfs()
{
    // 初始化
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    q.push(init);
    dist[init] = 0;

    while(q.size())
    {
        // 初始化
        string str = q.front();
        q.pop();
        
        int pos = str.find('0');
        int x = pos % 3;
        int y = pos / 3;

        int cnt = dist[str];
        for (int i=0 ; i<4 ; i++)
        {
            // 会被修改的值一定要新开变量存，否则处理会很麻烦
            string s = str;
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx>=0 && tx<3 && ty>=0 && ty<3) // 如果没越界
            {
                // 状态转换
                swap(s[ty*3+tx], s[y*3+x]);
                // 如果没到达过状态
                if(!dist.count(s)) 
                {
                    dist[s] = cnt+1;
                    q.push(s);
                }
                // 注意未到达过也不能continue！因为没swap回来！
                if(s == tar) 
                {
                    return;
                }
            }
        }
    }
    return;
}

int main()
{
    cin >> init;

    bfs();

    printf("%d",dist[tar]);

    return 0;
}

// 重点
// 1. 使用字符串存储棋盘，方便存储（一维下标 = ty * 3 + tx）
// 2. 用unordered_map存储棋盘和dist的对应关系