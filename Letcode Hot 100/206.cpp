// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

// 示例 1：


// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]
// 示例 2：


// 输入：head = [1,2]
// 输出：[2,1]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目范围是 [0, 5000]
// -5000 <= Node.val <= 5000
 

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

/// 【递归】注意递归函数中反转后的最后一个节点的next指向nullptr
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* ans = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }
};


/// 【迭代】注意操作反转时需要总共三个指针（cur反转的节点，pre反转节点前的节点，nxt下一个节点）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;// 注意pre的初始化！
        ListNode* cur = head;
        while(cur)
        {
            // 将cur节点->next反转
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};