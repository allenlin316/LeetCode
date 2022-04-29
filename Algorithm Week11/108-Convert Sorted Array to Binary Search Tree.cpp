#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* solve(vector<int>& nums, int start, int end);
TreeNode* sortedArrayToBST(vector<int>& nums);
void print(TreeNode *head); // binary-tree BFS

int main()
{
    int num;
    vector<int> nums;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')   break;
    }
    TreeNode *head = sortedArrayToBST(nums);
    print(head);
}

TreeNode* solve(vector<int>& nums, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode *newNode = new TreeNode(nums[mid]);
    newNode->left = solve(nums, start, mid-1);
    newNode->right = solve(nums, mid+1, end);
    return newNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    // [-10,-3,0,5,9]
    return solve(nums, 0, nums.size()-1);
}

void print(TreeNode *head){
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
