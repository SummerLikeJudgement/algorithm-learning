**各算法模板**

------------
# 排序
## 快速排序

```cpp
void quick_sort(int q[], int l, int r)
{
    if (l>=r) return;

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
        {
            tmp[k++] = q[i++];
        }
        else
        {
            tmp[k++] = q[j++];
        }
    }
    //将剩余的序列放到tmp
    while(i<=mid)
    {
        tmp[k++] = q[i++];
    }
    while(j<=r)
    {
        tmp[k++] = q[j++];
    }
    //将tmp复制回q
    for (i = l, j = 0 ; i<=r ; i++, j++)
    {
        q[i] = tmp[j];
    }
}
```
## 拓扑排序

# 双指针算法

```cpp
for (int i=0, j=0 ; i<n ; i++)
{
    while(j<i && check(i,j)) j++;

    //每个题目的具体逻辑/计算答案
}
```
# 位运算
```cpp
n >> k & 1 //求n的第k位数字 
lowbit(n) = n & -n //返回n的最后一位1
```

# 数据结构
模板参考：https://www.acwing.com/blog/content/404/
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
```cpp
常见模型：找出每个数左边离它最近的比它大/小的数
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    // 具体操作
    stk[ ++ tt] = i;
}
```
## 队列
```cpp
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1; // 边界具体值根据自己的习惯
// 向队尾插入一个数
q[ ++ tt] = x;
// 从队头弹出一个数
hh ++ ;
// 队头的值
q[hh];
// 判断队列是否为空，如果 hh <= tt，则表示不为空
if (hh <= tt) {}
```
### 单调队列
```cpp
常见模型：找出滑动窗口中的最大值/最小值
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}
```
- 本质上单调队列和单调栈的原理相同，只是多了个滑动窗口的实现
## KMP

## Trie
```cpp
int son[N][26]; //字符串总长度最多N,只有26种字符。下标为0的点既是根结点,也是空结点
int cnt[N];//结点的单词数
int idx;//当前用到的节点

void insert(char str[])
{
    int p=0;
    for (int i=0 ; str[i] ; i++)
    {
        int u = str[i]-'a';
        if (!son[p][u]) // 如果不存在子节点
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

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
```cpp
int p[N];// 存储每个编号的父节点

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
if(find(a) == find(b))
    printf("Yes\n");
else
    printf("No\n");
```

## 堆
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
memset(h, 0x3f, sizeof h); // memset 是按字节设置的，不是按 int 设置的！
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
ULL h[N]; // 哈希表
ULL p[N]; // 预计算存储P^i
// 判断[l,r]的hash值
ULL get(int l, int r)
{
    return h[r] - h[l-1]*p[r-l+1];
}

p[0] = 1;
//初始化，求p和字符串前缀h
for(int i=1 ; i<=n ; i++)
{
    p[i] = p[i-1]*P;
    h[i] = h[i-1]*P + str[i];
}
```

## 树和图
所有的树与图都能用有向图表示
```cpp
// 将一个单链表分为多个点的单链表
int h[N];// 储存每个点链表的头指针
int e[N]; // 当前节点当前的值
int ne[N]; // 当前节点的下一个节点的指针
int idx;// 链表使用到的节点

// 添加一条边a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// 初始化
idx = 0;
memset(h, -1, sizeof h);// -1代表没有指向任何节点
```


## STL
1. vector
```
vector, 变长数组，倍增的思想
    size()  返回元素个数
    empty()  返回是否为空
    clear()  清空
    front()/back()
    push_back()/pop_back() 增加/删除元素
    begin()/end()
    []
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
`#include <queue>`
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
    clear()
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
## 树和图的遍历
所有树和图都能本质用有向图表示
时间复杂度**O(n+m)**（n表示点数，m表示边数）
1. DFS
```cpp
int dfs(int u) // 编号u的点处的dfs
{
    st[u] = true; // 点u已经被遍历
    for(int i=h[u] ; i!=-1 ; i=ne[i]) // 手写邻接表存储点
    {
        int j = e[i];
        if(!st[j])
            dfs(j);
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
n表示点的个数
m表示边的条数
### 朴素Dijkstra
用于稠密图（n^2与m同一数量级）
```cpp

```
### 堆优化Dijkstra
用于稀疏图（n与m同一数量级）
```cpp
```