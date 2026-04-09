**各算法模板**

------------
# 排序
模板参考：https://www.acwing.com/file_system/file/content/whole/index/content/3190/
## 快速排序
- 不稳定的
```cpp
void quick_sort(int q[], int l, int r)
{
    if(l>=r) return;

    int x = q[l]; //取base元素
    int i = l-1, j = r+1; //注意指针要放在边界两侧，为了后面指针移动方便
    while(i<j)
    {
        while(q[++i] < x)
        {} //移动左指针
        while(q[--j] > x)
        {} //移动右指针
        if (i<j) //交换元素
        {
            swap(q[i], q[j]);
        }
    }
    //递归处理
    quick_sort(q, l, j); // 以j作为边界，x就不能为q[r];以i作为边界，x就不能为q[l]
    quick_sort(q, j+1, r); // 即不能取到边界，否则会死循环(同一个区间无限递归)
}
```

## 归并排序
- 稳定的，更适合链式存储
```cpp
void merge_sort(int q[], int l, int r)
{
    if (l>=r) return;
    //基准元素
    int mid = l+r >> 1;
    //递归排序
    merge_sort(q, l, mid); merge_sort(q, mid+1, r);
    //归并
    int k=0, i=l ,j=mid+1;
    while(i<=mid && j<=r)
    {
        if (q[i]<=q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    //将剩余的序列放到tmp
    while(i<=mid)
        tmp[k++] = q[i++];
    while(j<=r)
        tmp[k++] = q[j++];
    //将tmp复制回q
    for (i = l, j = 0 ; i<=r ; i++, j++)
        q[i] = tmp[j];
}
```
## 拓扑排序
```cpp
int n, m;// 点和边数量
// 存储图
int h[N], ne[N], e[N];
int idx;
// 队列
int q[N];
int hh, tt;
// 每个点的入度
int d[N]; // 在读入边时记录
// 返回图存在拓扑排序。q中就是拓扑序列
bool tolsort()
{
    // 初始化
    tt = -1; hh = 0;
    for(int i=1 ; i<=n ; i++)// 找到所有入度为0的点
        if(d[i] == 0)
            q[++tt] = i;
    while(tt>=hh)
    {
        int t = q[hh--];
        for(int i=h[t] ; i!=-1 ; i=ne[i])// 遍历删除所有出边，更新入度
        {
            int j = e[i];
            d[j]--;
            if(d[j] == 0)
                q[++tt] = j;
        }
    }
    
    return tt == n-1;// 如果读入n-1个点，则存在拓扑序列，否则没有
}
```
# 双指针算法

```cpp
for (int i=0, j=0 ; i<n ; i++)
{
    while(j<i && check(i,j)) j++;

    //每个题目的具体逻辑/计算答案
}
```
# 二分
## 整数/离散二分
```cpp
int q[N]; // 有序数组
int n; // 数组长度
// 找左区间的右端点
int binary_search1(int x) // 返回x所在的下标
{
    int l = 0, r = n-1;
    while(l<r)
    {
        int mid = l+r+1 >> 1;
        if(check(mid)) // mid在左区间
            l=mid;
        else // mid在右区间
            r=mid-1;
    }
    return l;
}
// 找右区间的左端点
int binary_search2(int x)
{
    int l = 0, r = n-1;
    while(l<r)
    {
        int mid = l+r >> 1;
        if(check(mid)) // mid在左区间
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
```
## 浮点数二分
- 保留4位小数，1e-6;保留5位小数，1e-7;保留6位小数，1e-8
```cpp
double binary_search(double l, double r)
{
    while(r-l>1e-8)
    {
        double mid = (l+r) / 2;
        if(check(mid)) // 在右区间
            r=mid;
        else(check(mid)) // 在左区间
            l=mid;
    }
    return l;
}
```
# 前缀和
## 1维前缀和
```cpp
// 计算前缀和数组
for (int i=1 ; i<=n ; i++) // 从下标1开始，避免边界问题
    S[i] = S[i-1]+a[i];
// 使用前缀和数组计算区间
ans = S[r]-S[l-1];
```
## 2维前缀和
```cpp
// 计算前缀和数组
for (int i=1 ; i<=n ; i++) // 从下标1开始，避免边界问题
    for (int j=1 ; j<=m ; j++)
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
// 使用前缀和数组计算区间
ans = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
```
# 差分
## 1维差分
```cpp
int A[N];// 初始数组
int B[N];// 差分数组
// 初始数组的[l,r]区间的元素都加上c
void insert(int l, int r, int c)
{
    B[r+1] -= c;
    B[l] += c;
}
// 构造初始差分数组
for(int i=1 ; i<=N ; i++) insert(i, i, A[i]);
```
## 2维差分
```cpp
int A[N][N];// 初始数组
int B[N][N];// 差分数组
// 初始数组的(x1,y1)~(x2,y2)的元素都加上c
void insert(int x1, int y1, int x2, int y2, int c) // x2>x1,y2>y1
{
    B[x1][y1] += c;
    B[x2+1][y1] -= c;
    B[x1][y2+1] -= c;
    B[x2+1][y2+1] += c;
}
// 构造初始差分数组
for(int i=1 ; i<=N ; i++)
    for(int j=1 ; j<=N ; j++)
        insert(i, j, i, j, A[i][j]);
```
# 位运算
```cpp
int x = (n >> k) & 1 //求二进制n的第k位数字 
int lowbit(n){n & -n} //返回n的最后一位1
```
# 离散化

```cpp
vector<int> alls;// 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());// 去掉重复元素
// 二分求x对应的离散化的值
int find(int x)
{
    int l=0, r=alls.size()-1;
    while(l<r)
    {
        int mid = l+r+1 >> 1;
        if(alls[mid]<=x)
            l=mid;
        else
            r=mid-1;
    }
    return l+1;// 映射到1, 2, ...n
}
```
# 区间合并
将所有存在交集的区间合并
```cpp
void merge_segs(vector<PII> &segs)
{
    sort(segs.begin(), segs.end());

    int st=-2e8, ed=-2e8;
    vector<PII> ans;
    for(auto seg : segs)
    {
        if(seg.first > ed)
        {
            if(st!=-2e8) 
                ans.push_back({st,ed});
            st = seg.first, ed = seg.second;
        }
        else
            ed = max(ed, seg.second);
    }
    if(st!=-2e8)
        ans.push_back({st,ed});
    segs = ans;
}
```
# 数据结构
模板参考：https://www.acwing.com/blog/content/404/
## 链表
### 单链表
- head存储链表头
- e[]存储节点的值
- ne[]存储节点的next指针
- idx表示当前用到了哪个节点
```cpp
int head, e[N], ne[N], idx;
// 初始化
void init()
{
    head = -1;
    idx = 0;
}
// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}
// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}
```
#### 邻接表
用于存储有向图
```cpp
int h[N], e[N], ne[N], idx;
// 初始化
memset(h, -1, sizeof h);
idx = 0;
// 增加x->y的边
void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    idx++;
}
```
### 双链表
- e[]表示节点的值
- l[]表示节点的左指针，r[]表示节点的右指针
- idx表示当前用到了哪个节点
```cpp
int e[N], l[N], r[N], idx;
// 初始化
void init()
{
    //固定下标0是左端点，下标1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}
// 在下标a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}
// 删除下标a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}
```
## 栈
- 下标0位置不存放元素
- tt指向栈顶位置的元素
```cpp
// tt表示栈顶
int stk[N], tt = 0;
// 向栈顶插入一个数
stk[ ++ tt] = x;
// 从栈顶弹出一个数
tt -- ;
// 栈顶的值
stk[tt];
// 判断栈是否为空，如果 tt > 0，则表示不为空
if (tt > 0) {}
```
### 单调栈
常见模型：找出每个数左边离它最近的比它大/小的数
```cpp
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    // 具体操作
    stk[ ++ tt] = i;
}
```
## 队列
- hh 指向队头元素，tt 指向队尾元素
```cpp
int q[N], hh = 0, tt = -1; // 边界具体值根据自己的习惯
// 向队尾插入一个数
q[ ++ tt] = x;
// 从队头弹出一个数
hh ++ ;
// 队头的值
q[hh];
// 判断队列是否为空，hh <= tt 表示不为空
if (hh <= tt) {}
```
### 循环队列
- hh 指向队头元素，tt 指向队尾元素的后一个位置
```cpp
// 初始化
int q[N], hh = 0, tt = 0;
// 向队尾插入一个数
q[tt ++ ] = x;
if (tt == N) tt = 0;
// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;
// 队头的值
q[hh];
// 判断队列是否为空，如果hh != tt，则表示不为空
if (hh != tt) {}
```
### 单调队列
常见模型：找出滑动窗口中的最大值/最小值
```cpp
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) // 判断队头是否滑出窗口
        hh ++ ;  
    while (hh <= tt && check(q[tt], i)) // 维护队列的单调性
        tt -- ;
    q[ ++ tt] = i;
}
```
- 本质上单调队列和单调栈的原理相同，只是多了个滑动窗口的实现
## KMP
- s是目标串，p是模板串
- ne表示前i-1个字符匹配而第i个字符不匹配时回退到的位置
```cpp
char s[N], p[N];// 从下标1开始
int ne[N];
// 递归初始化ne
for(int i=2, j=0 ; i<=n ; i++)// i从2开始（ne[1]=0）
{
    while(j && p[i]!=p[j+1])
        j = ne[j];
    if(p[i] == p[j+1])
        j++;
    ne[i] = j;
}
// s匹配p
for(int i=1, j=0 ; i<=m ; i++)
{
    while(j && s[i]!=p[j+1])
        j=ne[j];
    if(s[i] == p[j+1])
        j++;
    if(j == n)
    {
        // 找到s中匹配p的起始下标i-n+1
        j = ne[j];
    }
}
```

## Trie
- 下标`[0][0]`的点既是根结点,也是空结点
```cpp
int son[N][M]; //字符串总长度最多N,有M种字符
int cnt[C];//结点的单词数
int idx;//当前用到的节点
// 插入
void insert(char str[])
{
    int p = 0;// 从根结点开始
    for (int i=0 ; str[i] ; i++)
    {
        int u = str[i]-'a';
        if (!son[p][u]) // 如果不存在子节点
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
// 查找
int query(char str[])
{
    int p = 0;
    for (int i=0 ; str[i] ; i++)
    {
        int u = str[i]-'a';
        if(son[p][u])
            p = son[p][u];
        else
            return 0;
    }
    return cnt[p];
}
```
## 并查集
- p存储每个编号的父节点
```cpp
int p[N];

//初始化，每个元素分别在一个树
for(int i=1 ; i<=n ; i++)
    p[i] = i;
//返回编号x的祖宗节点+路径压缩
int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
// 合并集合
p[find(a)] = find(b); // 使a的祖宗节点成为b的子节点
// 询问集合
if(find(a) == find(b)) else
```

## 堆
实现的是小根堆，利用up和down可实现：将x插入堆、求堆中的最小值、删除堆中最小值、删除任意一个元素、修改任意一个元素
- h从下标1开始存储
```cpp
int h[N], size_;//堆，堆当前存入的个数

// 将x位置的节点尝试down
void down(int x)
{
    int t = x;// t存储三个节点中最小的数的下标
    if (x*2 <= size_ && h[x*2] < h[t]) t = x*2;
    if (x*2+1 <= size_ && h[x*2+1] < h[t]) t = x*2+1;

    if (x != t)
    {
        swap(h[t], h[x]);
        down(t);
    }
}
// 将x位置的节点尝试up
void up(int x)
{
    while(x/2 && h[x/2]>h[x]) // 当父节点存在并且更大
    {
        swap(h[x/2], h[x]);
        x /= 2;
    }
}
// O(n)将无序数组h[n]建堆
for(int i=n/2 ; i ; i--)
    down(i);
```

## 哈希表
1. 开放寻址法
```cpp
const int N = 200003; // 最好用质数（编程遍历求），并且是题目数据范围的2~3倍
const int null = 0x3f3f3f3f; // 约定数据范围之外的数表示空

int h[N];// hash数组

// 如果x在hash中，返回位置；如果x不在hash中，返回应该存的位置
int find(int x)
{
    int k = (x % N + N) % N; // 确保k是正数

    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if (k == N) 
            k=0;
    }
    return k;
}
//初始化
memset(h, 0x3f, sizeof h); // memset是按字节赋值的
```

2. 拉链法
```cpp
const int N = 100003; // 最好用质数（编程遍历求）

int h[N];// hash数组，每个位置相当于head头指针，指向链表中第一个节点（-1表示空）
int e[N], ne[N], idx;// 用一个链表存储所有hash的N条链（将链表拆为N个链）
//向表中插入x
void insert(int x)
{
    int k = (x % N + N) % N; // 确保k是正数
    //将x插入链表中
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}
// 表中查找x
bool find(int x)
{
    int k = (x % N + N) % N; // 确保k是正数

    for (int i=h[k] ; i!=-1 ; i=ne[i])
        if(e[i] == x) return true;
    return false;
}
//初始化
memset(h, -1, sizeof h); //将h清空，全部置为-1
```

- 两个方法基本相同
### 字符串前缀哈希
```cpp
const int N = 1e5+10;
const int P = 131;// 131或13331

char str[N];
ULL h[N]; // 哈希表，usigned long long相当于mod2^64
ULL p[N]; // 预计算存储P^i
// 判断[l,r]的hash值
ULL get(int l, int r)
{
    return h[r] - h[l-1]*p[r-l+1];
}

//初始化，求P^i和字符串前缀h
p[0] = 1;
for(int i=1 ; i<=n ; i++)
{
    p[i] = p[i-1]*P;
    h[i] = h[i-1]*P + str[i];
}
```

## 树和图
所有的树与图都能用有向图表示
1. 邻接表
```cpp
// 将一个单链表分为多个点的单链表
int h[N];// 储存每个点链表的头指针
int e[N]; // 当前节点当前的值
int ne[N]; // 当前节点的下一个节点的指针
int idx;// 链表使用到的节点
int w[N]; // 储存每条边的权重

// 添加一条边a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// 初始化
idx = 0;
memset(h, -1, sizeof h);// -1代表没有指向任何节点
```
2. 邻接矩阵
```cpp
int g[N][N];
// 添加一条边a->b，权重为w
void add(int a, int b, int w)
{
    g[a][b] = w;
}
```

## STL
1. vector
```
vector, 变长数组，倍增的思想
    size()  返回元素个数
    empty()  返回是否为空
    clear()  清空
    front()/back()  返回开头/末尾元素
    push_back()/pop_back() 在末尾增加/删除元素
    begin()/end()
    []  访问元素
    支持比较运算，按字典序
```
- 使用vector要尽量减少增加空间的次数

2. pair
```
pair<int, int>
    first, 第一个元素
    second, 第二个元素
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
```

3. string
```
string，字符串
    size()/length()  返回字符串长度
    empty()
    clear()
    substr(起始下标，(子串长度))  返回子串
    c_str()  返回字符串所在字符数组的起始地址
```

4. queue
`#include <queue>`导入
```
queue, 队列
    size()
    empty()
    push()  向队尾插入一个元素
    front()  返回队头元素
    back()  返回队尾元素
    pop()  弹出队头元素
```

5. priority_queue
`#include <queue>`导入
```
priority_queue, 优先队列，默认是大根堆(堆顶元素最大)
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    定义成小根堆(堆顶元素最小)的方式：priority_queue<int, vector<int>, greater<int>> q;
```

6. stack
```
stack, 栈
    size()
    empty()
    push()  向栈顶插入一个元素
    top()  返回栈顶元素
    pop()  弹出栈顶元素
```

7. duque
```
deque, 双端队列
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []
```

8. hash
```
set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
    size()
    empty()
    clear()  删除所有元素
    begin()/end()
    ++, -- 返回前驱和后继，时间复杂度 O(logn)

    set/multiset
        insert()  插入一个数
        find()  查找一个数
        count()  返回某一个数的个数
        erase()
            (1) 输入是一个数x，删除所有x   O(k + logn)
            (2) 输入一个迭代器，删除这个迭代器
        lower_bound()/upper_bound()
            lower_bound(x)  返回大于等于x的最小的数的迭代器
            upper_bound(x)  返回大于x的最小的数的迭代器
    map/multimap
        insert()  插入的数是一个pair
        erase()  输入的参数是pair或者迭代器
        find()
        []  注意multimap不支持此操作。 时间复杂度是 O(logn)
        lower_bound()/upper_bound()
```
```
unordered_set, unordered_map, unordered_multiset, unordered_multimap, 基于哈希表
    和上面类似，增删改查的时间复杂度是 O(1)
    不支持 lower_bound()/upper_bound()， 迭代器的++，--
```

9. bitset
```
bitset, 圧位
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  返回有多少个1

    any()  判断是否至少有一个1
    none()  判断是否全为0

    set()  把所有位置成1
    set(k, v)  将第k位变成v
    reset()  把所有位变成0
    flip()  等价于~
    flip(k) 把第k位取反
```

# 搜索与图论
模板参考：https://www.acwing.com/file_system/file/content/whole/index/content/3272/

- n表示点的个数，m表示边的条数
## 树和图的遍历
所有树和图本质都能用有向图表示
- 时间复杂度**O(n+m)**
1. DFS
```cpp
bool st[N];
int dfs(int u) // 编号u的点处的dfs
{
    st[u] = true; // 点u已经被遍历
    for(int i=h[u] ; i!=-1 ; i=ne[i]) // 手写邻接表存储点
    {
        int j = e[i];
        if(!st[j])
            dfs(j); // 图的遍历不需要回溯
    }
}
```

2. BFS
```cpp
// 初始化
queue<int> q; // 记录遍历的点
st[1] = true; // 1号点已经遍历
q.push(1); 
while(q.size())
{
    int t = q.front();
    q.pop();
    for(int i=h[t] ; i!=-1 ; i=ne[i]) // 手写邻接表存储点
    {
        int j = e[i];
        if(!st[j])
        {
            q.push(j);
            st[j] = true;
        }
    }
}
```

## 最短路问题

### 朴素Dijkstra
用于稠密图（n^2与m同一数量级）+正权边+单源最短路
- 时间复杂度**O(n^2+m)**
```cpp
int g[N][N];
int dist[N];
bool st[N];
// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i=0 ; i<n ; i++) // 起始点已经确定，只需遍历n-1次
    {
        int t = -1;
        // 找到非st的距离最小的点
        for(int j=1 ; j<=n ; j++)
            if(!st[j] && (t==-1 || dist[j]<dist[t])) t = j;
        // 更新所有点的距离
        for(int j=1 ; j<=n ; j++)
            dist[j] = min(dist[j], dist[t]+g[t][j]);
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dsit[n];
}
```
### 堆优化Dijkstra
用于稀疏图（n与m同一数量级）+正权边+单源最短路
- 时间复杂度**O(mlogn)**
```cpp
// 邻接表存储所有边
int h[N], w[N], e[N], ne[N], idx;

bool st[N];
int dist[N];
// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0,1}); // {距离,编号}

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int distance = t.first, u = t.second;
        if(st[u]) 
            continue;
        st[u] = true;

        for(int i=u ; i!=-1 ; i=ne[i])
        {
            int j = e[i];
            if(dist[j] > distance+w[j])
            {
                dist[j] = distance+w[j];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}
```
### Bellman-Ford
适用于正负权边+单源最短路 -> 判断负权环
- 时间复杂度**O(mn)**
```cpp
struct Edge
{int a, b, w}edges[M];

int dist[N];
int backup[N]; // 有负权回路时，每次循环需要备份dist
// 求1号点到n号点不超过k条边的最短距离，如果不存在，则返回-1
int Bellman_Ford()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i=0 ; i<k ; i++) // 循环k次，找到经过k条边的最短路径
    {
        memcpy(backup, dist, sizeof dist);
        for(int j=1 ; j<=m ; j++)
        {
            auto e = edges[j];
            if(dist[e.b] > backup[e.a]+e.w)
                dist[e.b] = backup[e.a] + e.w;
        }
    }
    if(dist[n] > 0x3f3f3f3f/2) return -1; // 遍历了所有边，所以有些dist会稍微小于INF
    else return dist[n];
}
```
#### 找负权环
```cpp
struct Edge
{int a, b, w}edges[M];

int dist[N];
int backup[N]; // 有负权回路时，每次循环需要备份dist
// 判断图是否存在负权环，如果不存在，则返回false
bool Bellman_Ford()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i=0 ; i<n-1 ; i++) // 循环n-1次
    {
        memcpy(backup, dist, sizeof dist);
        for(int j=1 ; j<=m ; j++)
        {
            auto e = edges[j];
            if(dist[e.b] > backup[e.a]+e.w)
                dist[e.b] = backup[e.a] + e.w;
        }
    }
    // 第n次循环
    for(int j=1 ; j<=m ; j++)
    {
        auto e = edges[j];
        if(dist[e.b] > dist[e.a]+e.w)
            return true;
    }
    return false;
}
```
### SPFA
适用于正负权边+单源最短路 -> 判断负权环
- 时间复杂度一般**O(m)**，最大**O(mn)**
```cpp
int h[N], ne[N], e[N], w[N], idx; // 存储图
int dist[N]; // 存储1号点到i的最短距离
bool st[N]; // 存储每个点是否在队列中

int SPFA()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front()
        q.pop();
        st[t] = false;

        for(int i=h[t] ; i!=-1 ; i=ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t]+w[t])
            {
                dist[j] = dist[t] + w[t];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}
```
#### 找负权环
```cpp
int h[N], ne[N], e[N], w[N], idx; // 存储图
int dist[N]; // 存储虚拟起点到i号点的最短距离
bool st[N]; // 存储每个点是否在队列中
int cnt[N]; // 存储虚拟起点到i号点最短路径的边数

bool spfa()
{
    // 初始化，初始化dist数组为dist[i]=0
    queue<int> q;
    for(int i=1 ; i<=n ; i++)
    {
        q.push(i);
        st[i] = true;
    }

    while(q.size())
    {
        int t = q.fornt();
        q.pop();
        st[t] = false;

        for(int i=h[t] ; i!=-1 ; i=ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[i]+w[j])
            {
                cnt[j] = cnt[i] + 1;
                dist[j] = dist[i]+w[j];
                if(dist[j] >= n)
                    return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
```
### Floyd
适用于正负权边+无负权环+多源最短路+稠密图
- 时间复杂度**O(n^3)**
```cpp
int g[N][N]; // 存储图
// 初始化
for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=n ; j++)
        if(i == j) g[i][j] = 0;
        else g[i][j] = INF;
// 算法结束后，g[a][b]表示a到b的最短距离
void floyd()
{
    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
}
```
## 最小生成树
### 朴素Prim
适用于稠密图
- 时间复杂度**O(n^2)**
```cpp
int g[N][N]; // 存储图
bool st[N]; // 存储每个点是否已经在生成树中
int dist[N]; // 表示点到当前最小生成树的最小距离
// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int Prim()
{
    // 初始化
    int ans = 0;
    memset(dist, 0x3f, sizeof dist);
    for(int i=0 ; i<n ; i++)// 循环n次，因为没有提前确定最短路径的点了
    {
        int t = -1;
        // 找到非st的距离集合最短的点
        for(int j=1 ; j<=n ; j++)
        {
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t = j;
        }

        st[t] = true;
        if(i && dist[t]==INF) return INF;
        if(i) ans += dist[t];
        for(int j=1 ; j<=n ; j++)
            dist[j] = min(dist[j], g[t][j]); 
    }
    return ans;
}
```
### Kruskal
- 时间复杂度**O(mlogn)**
```cpp
int p[N];

struct Edge
{
    int a, b, w;
    bool operate< (const Edge &W)const // 重载<，便于排序
    {
        return w<W.w;
    }
}edges[M];

int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    // 初始化
    sort(edges, edges+m);
    for(int i=1 ; i<=n ; i++)
        p[i] = i;
    int res = 0, cnt = 0;
    
    for(int i=0 ; i<m ; i++)
    {
        auto t = edges[i];
        int a = find(t.a), b = find(t.b), w = t.w;
        if(a != b) // 如果两个连通块不连通，则将这两个连通块合并
        {
            p[find(a)] = find(b);
            res += w;
            cnt++;
        }
    }
    if(cnt < n-1) return INF;
    return res;
}
```
## 二分图
### 染色法
适用于判断图是否是二分图
- 时间复杂度**O(m+n)**
```cpp
int h[N], e[M], ne[M], idx; // 邻接表存储图
int color[N]; // 表示每个点的颜色，0表示未染色，1/2表示两种颜色
// u号点的染色。如果出现矛盾返回false
bool dfs(int u, int c)
{
    color[u] = c;
    for(int i=h[u] ; i!=-1 ; i=ne[i])
    {
        int j = e[i];
        if(color[j] == 0) // 未被染色
        {
            if(!dfs(j, 3-c))
                return false;
        }
        else // 被染色
        {
            if(color[j] == 3-c)
                return false;
        }
    }
    return true;
}

bool check()
{
    // 初始化
    memset(h, -1, sizeof h);
    // 遍历所有点（可能不是连通图）
    for(int i=1 ; i<=n ; i++)
        if(!color[i]) // 未被染色
            if(!dfs(i, 1))
                return false;
    return true;
}
```
### 匈牙利算法
适用于找到二分图的最大匹配
- 时间复杂度**O(mn)**（实际运行时间远小于）
- 只需要存一个方向的边
```cpp
int h[N], e[M], ne[M], idx; // 邻接表存储所有边
int match[N]; // 存储第二个集合中的每个点当前匹配的第一个集合中的点
bool st[N]; // 表示第二个集合中的每个点是否已经被遍历过
// 第一个集合元素x是否能找到
bool find(int x)
{
    for(int i=h[x] ; i!=-1 ; i=ne[i]) // 遍历所有边
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j]==0 || find(match[j])) // 未匹配或已匹配但能更换
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int res = 0;
// 依次枚举第一个集合中的每个点能否匹配第二个集合中的点
for(int i=1 ; i<n1 ; i++)
{
    memset(st, false, sizeof st);
    if(find(i)) res++;
}
```