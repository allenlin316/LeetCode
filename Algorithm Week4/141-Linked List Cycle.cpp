// 改過 while 判斷式寫法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *faster_pointer = head;
        ListNode *cur = head;
        while(faster_pointer != NULL && faster_pointer->next != NULL){  // 因為 faster_pointer 可能會指到 NULL
            faster_pointer = faster_pointer->next->next;
            cur = cur->next;
             if(faster_pointer == cur) // 代表有 cycle
                return true;
        }
        return false;
    }
};
