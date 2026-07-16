// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

// 示例 1：


// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]
// 示例 2：

// 输入：head = [1], n = 1
// 输出：[]
// 示例 3：

// 输入：head = [1,2], n = 1
// 输出：[1]
 

// 提示：

// 链表中结点的数目为 sz
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 

// 进阶：你能尝试使用一趟扫描实现吗？

/// 【双指针】r比l超前n个节点，r遍历到链表末尾即可
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l = head;
        ListNode* r = head;
        int len = 0;
        while(r->next)
        {
            r = r->next;
            if(len == n)
                l = l->next;
            else
                len++;
        }
        if(len == n)
            l->next = l->next->next;
        else
            head = head->next;
        
        return head;
    }
};

/// 【栈】遍历链表的同时将所有节点依次入栈，弹出栈的第 n 个节点就是需要删除的，并且目前栈顶的节点就是待删除节点的前驱节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); // 新建头节点，防止边界问题
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
