// 改過 while 判斷式後
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *faster_pointer = head;
        ListNode *cur = head;
        while(faster_pointer != NULL && faster_pointer->next != NULL){
            faster_pointer = faster_pointer->next->next;
            cur = cur->next;
             if(faster_pointer == cur)
                return true;
        }
        return false;
    }
};
