// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

// 示例 1：


// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：

// 输入：head = []
// 输出：[]
// 示例 3：

// 输入：head = [1]
// 输出：[1]
 

// 提示：

// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100


/// 【迭代】
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 全为空或只有一个节点
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* l = new ListNode(0, head);
        ListNode* mid = head;
        ListNode* r = head->next;
        while(l && mid && r)
        {
            // 交换
            l->next = mid->next;
            mid->next = r->next;
            r->next = mid;
            if(head == mid)
                head = r;
            // 更新
            l = l->next->next;
            if(!mid->next) return head;
            mid = mid->next;
            if(!r->next->next->next) return head;
            r = r->next->next->next;
        }

        return head;
    }
};

/// 【归并】
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 全为空或只有一个节点
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* l = new ListNode(0, head);
        ListNode* mid = head;
        ListNode* r = head->next;
        while(l && mid && r)
        {
            // 交换
            l->next = mid->next;
            mid->next = r->next;
            r->next = mid;
            if(head == mid)
                head = r;
            // 更新
            l = l->next->next;
            if(!mid->next) return head;
            mid = mid->next;
            if(!r->next->next->next) return head;
            r = r->next->next->next;
        }

        return head;
    }
};