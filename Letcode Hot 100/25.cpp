// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

// 示例 1：


// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]
// 示例 2：



// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]
 

// 提示：
// 链表中的节点数目为 n
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？


/// 【栈】利用栈实现反转
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
        ListNode* h = head;
        // k个节点入栈
        for(int i=0 ; i<k ; i++)
        {
            s.push(h);
            if(h)
                h = h->next;
            else // 不足k个节点
                return head;
        }
        ListNode* ans = s.top();
        ListNode* now = ans;
        s.pop();
        for(int i=1 ; i<k ; i++)
        {
            now->next = s.top();
            s.pop();
            now = now->next;
        }
        now->next = reverseKGroup(h, k);
        return ans;
    }
};


/// 【迭代】使用三个指针实现迭代反转。注意prev的初始化取值！
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;

        for (int i = 0; i < k; i++) {
            if (tail == nullptr)
                return head;
            tail = tail->next;
        }

        ListNode* prev = tail;
        ListNode* cur = head;

        while (cur != tail) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        head->next = reverseKGroup(cur, k);

        return prev;
    }
};