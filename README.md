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
