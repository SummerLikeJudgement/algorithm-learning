// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

 

// 示例 1：


// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 示例 2：


// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目在范围 [0, 5 * 104] 内
// -105 <= Node.val <= 105
 

// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？


/// 【归并排序】自顶向下，手搓归并排序即可。注意链表和数组有些区别
class Solution {
public:
    // 对链表进行归并排序
    ListNode* merge_sort(ListNode* head)
    {
        // 只有一个节点
        if(!head->next)
            return head;
        // 快慢指针找到链表中点
        ListNode *l = head;
        ListNode* r = head;
        while(r->next && r->next->next)
        {
            l = l->next;
            r = r->next->next;
        }
        // 对两边排序
        ListNode* m1 = head;
        ListNode* m2 = l->next;
        l->next = nullptr;
        ListNode* t1 = merge_sort(m1);
        ListNode* t2 = merge_sort(m2);
        // 对两边归并
        if(t1->val <= t2->val)
        {
            head = t1;
            t1 = t1->next;
        }
        else
        {
            head = t2;
            t2 = t2->next;
        }

        ListNode* t = head;
        while(t1 && t2)
        {
            if(t1->val <= t2->val)
            {
                t->next = t1;
                t1 = t1->next;
            }
            else
            {
                t->next = t2;
                t2 = t2->next;
            }
            t = t->next;
        }
        while(t1)
        {
            t->next = t1;
            t1 = t1->next;
            t = t->next;
        }
        while(t2)
        {
            t->next = t2;
            t2 = t2->next;
            t = t->next;
        }
        return head;

    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
            return head;
        return merge_sort(head);
    }
};


/// 【归并排序】想要空间复杂度控制到常数，只能自底向上。先求得链表的长度，然后将链表拆分成子链表进行合并。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};