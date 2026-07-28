// 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

// 例如 arr = [2,3,4] 的中位数是 3 。
// 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
// 实现 MedianFinder 类:

// MedianFinder() 初始化 MedianFinder 对象。

// void addNum(int num) 将数据流中的整数 num 添加到数据结构中。

// double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

// 示例 1：

// 输入
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// 输出
// [null, null, null, 1.5, null, 2.0]

// 解释
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
// 提示:

// -105 <= num <= 105
// 在调用 findMedian 之前，数据结构中至少有一个元素
// 最多 5 * 104 次调用 addNum 和 findMedian


/// 【堆/优先队列】使用两个优先队列，分别存储大于（小根堆）和小于等于（大根堆）当前中位数的数
class MedianFinder {
public:
    // 小于等于中位数的数
    priority_queue<int, vector<int>, less<int>> queMin;// 大根堆
    // 大于中位数的数
    priority_queue<int, vector<int>, greater<int>> queMax;// 小根堆

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // num应该进入queMin
        if(queMin.empty() || num<=queMin.top())
        {
            queMin.push(num);
            if(queMax.size()+1 < queMin.size())
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        // num应该进入queMax
        else
        {
            queMax.push(num);
            if(queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if(queMin.size() > queMax.size())
            return queMin.top();
        else
            return (queMax.top() + queMin.top()) / 2.0;
    }
};
