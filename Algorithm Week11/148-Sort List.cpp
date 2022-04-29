#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* midPoint(ListNode *head);
ListNode* merge(ListNode *a, ListNode *b);
ListNode* mergeSort(ListNode *head);
ListNode* sortList(ListNode* head);

int main()
{
    ListNode *head;
    ListNode *cur;
    int num;
    cin >> num;
    cur = new ListNode(num);
    head = cur;
    while(cin >> num){
        cur->next = new ListNode(num);
        cur = cur->next;
        if(cin.get() == '\n')   break;
    }
    head = sortList(head);
    cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
}

ListNode* midPoint(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head->next->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // return middle
}

ListNode* merge(ListNode *a, ListNode *b){
    // base case
    if(a==NULL) return b;
    if(b==NULL) return a;

    // recursive case
    ListNode *c;
    // 指到小的那一個，剩下的再繼續做 merge
    if(a->val < b->val){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

ListNode* mergeSort(ListNode *head){
    // base case
    if(head == NULL || head->next == NULL)
        return head;
    // recursive case
    ListNode *mid = midPoint(head);

    // Break at the mid
    ListNode *a = head;
    ListNode *b = mid->next;
    mid->next = NULL; // in order to cut the sequence for a and b

    // Recursive Sort
    a = mergeSort(a);
    b = mergeSort(b);

    // Merge
    return merge(a, b);
}

ListNode* sortList(ListNode* head){
    return mergeSort(head);
}
/*
method 1 : turn linked-list into vector and sort
ListNode* sortList(ListNode* head) {
    if(head == NULL)    return NULL;
    vector<int> nums;
    while(head){
        nums.push_back(head->val);
        head = head->next;
    }
    sort(nums.begin(), nums.end());
    head = new ListNode(nums[0]);
    ListNode *cur = head;
    for(int i=1; i<nums.size(); i++){
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}*/
