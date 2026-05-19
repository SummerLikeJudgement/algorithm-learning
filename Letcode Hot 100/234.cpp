// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

 

// 示例 1：


// 输入：head = [1,2,2,1]
// 输出：true
// 示例 2：


// 输入：head = [1,2]
// 输出：false
 

// 提示：

// 链表中节点数目在范围[1, 105] 内
// 0 <= Node.val <= 9
 

// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

/// 【数组+双指针】
/// 将链表输入到数组中，使用双指针从左右两边遍历判断是否回文
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
    bool isPalindrome(ListNode* head) {
        int num[100010];
        int cnt = 0;
        while(head)
        {
            num[cnt++] = head->val;
            head = head->next;
        }
        int i = 0, j = cnt-1;
        while(i<=j)
        {
            if(num[i++] != num[j--])
                return false;
        }

        return true;
    }
};

/// 【双指针（快慢指针）+反转链表】
/// 快指针到链表最后，慢指针到链表正中，反转后半链表，判断是否回文
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
