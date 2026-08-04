// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

 

// 示例：

// 输入
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// 输出
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// 解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4
 

// 提示：

// 1 <= capacity <= 3000
// 0 <= key <= 10000
// 0 <= value <= 105
// 最多调用 2 * 105 次 get 和 put



/// 【双向链表+哈希】
struct DLinkedNode// 手写双向链表,按最近使用存储键值对
{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;// 存储key在链表中的位置
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity) { // 初始化
        capacity = _capacity;
        size = 0;
        // 使用伪头部和伪尾部
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        DLinkedNode* t = cache[key];
        // 最近访问移到链表头部
        moveToHead(t);
        return t->value;
    }
    
    void put(int key, int value) {
        // 找不到key
        if(cache.find(key) == cache.end())
        {
            DLinkedNode* t = new DLinkedNode(key, value);
            cache[key] = t;
            addToHead(t);
            size++;
            // 超出容量则删除最近未使用
            if(size > capacity)
            {
                DLinkedNode* dele = tail->prev;
                cache.erase(dele->key);
                removeNode(tail->prev);
                size--;
            }
        }
        // 找到key
        else
        {
            DLinkedNode* t = cache[key];
            t->value = value;
            // 最近使用
            moveToHead(t);
        }
    }

    // 将t移动到链表头部
    void moveToHead(DLinkedNode* t)
    {
        removeNode(t);
        addToHead(t);
    }

    void addToHead(DLinkedNode* t)
    {
        t->prev = head;
        head->next->prev = t;
        t->next = head->next;
        head->next = t;
    }

    void removeNode(DLinkedNode* t)
    {
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */