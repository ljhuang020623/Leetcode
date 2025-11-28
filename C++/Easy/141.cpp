/**
 * Definition for singly-linked list.
 */
#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow != fast){
                continue;
            }
            else{
                return true;
            }
        }
        return false;

    }
};