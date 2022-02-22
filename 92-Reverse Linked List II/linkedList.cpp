#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};
ListNode *head = NULL;

ListNode* createNode(int num){
    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = num;
    tmp->next = NULL;
    return tmp;
}

ListNode* reverseBetween(ListNode* head, int left, int right){
    ListNode *rightNext = NULL;
    ListNode *leftPre = NULL;
    ListNode *newList = NULL;
    ListNode *cur = head;
    if(left == right)   return head;
    for(int i=1; i<left; i++){
        leftPre = cur;
        cur = cur->next;
    }
    newList = cur;
    ListNode *newListHead = newList;
    for(int i=left; i<right; i++){
        newList->next = cur->next;
        newList = newList->next;
        cur = cur->next;
        rightNext = cur->next;
    }
    newList->next = NULL; // above: to get newList between left and right
    ListNode *revCur = newListHead;
    ListNode *revPre = NULL;
    ListNode *revNext = NULL;
    while(revCur != NULL){
        revNext = revCur->next;
        revCur->next = revPre;
        revPre = revCur;
        revCur = revNext;
    }
    newListHead->next = rightNext;
    newListHead = revPre;
    if(leftPre != NULL){
        leftPre->next = newListHead;
        //newListHead = leftPre;
        newListHead = head;
    }
    return newListHead;
}

void swap(int *num1, int *num2){
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main()
{
     ListNode *data1 = createNode(1);
    ListNode *data2 = createNode(2);
    ListNode *data3 = createNode(3);
    ListNode *data4 = createNode(4);
    ListNode *data5 = createNode(5);
    data1->next = data2;
    data2->next = data3;
    data3->next = data4;
    data4->next = data5;
    data5->next = NULL;
    head = data1;
//    while(head){
//        cout << head->val << " ";
//        head = head->next;
//    }
//    cout << endl;
    ListNode *reverseList;
    reverseList = reverseBetween(head, 1, 5);
    while(reverseList != NULL){
        cout << reverseList->val << " ";
        reverseList = reverseList->next;
    }
}
