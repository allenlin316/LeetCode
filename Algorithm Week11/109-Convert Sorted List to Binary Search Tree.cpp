#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* solve(vector<int> &nums, int start, int end);
TreeNode* sortedListToBST(ListNode* head);
void printTree(TreeNode *head);

int main()
{
    ListNode *head, *cur;
    int num;
    cin >> num;
    cur = new ListNode(num);
    head = cur;
    while(cin >> num){
        cur->next = new ListNode(num);
        cur = cur->next;
        if(cin.get() == '\n')   break;
    }
    printTree(sortedListToBST(head));
}

TreeNode* solve(vector<int> &nums, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode *newNode = new TreeNode(nums[mid]);
    newNode->left = solve(nums, start, mid-1);
    newNode->right = solve(nums, mid+1, end);
    return newNode;
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while(head){
        nums.push_back(head->val);
        head = head->next;
    }
    return solve(nums, 0, nums.size()-1);
}

void printTree(TreeNode *head){
    queue<TreeNode*> q;
    q.push(head);
    while(!q.empty()){
        TreeNode *cur = q.front();
        q.pop();
        if(cur == NULL){
                cout << "null ";
        }   else{
                cout << cur->val << " ";
                if(cur->left == cur->right && cur->left == NULL) continue;
                q.push(cur->left);
                q.push(cur->right);
        }
    }
}
