#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end);
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
void printTree(TreeNode *head);

int main()
{
    int num;
    vector<int> inorder;
    vector<int> preorder;
    while(cin >> num){
        preorder.push_back(num);
        if(cin.get() == '\n')   break;
    }
    while(cin >> num){
        inorder.push_back(num);
        if(cin.get() == '\n')   break;
    }
    TreeNode *head = buildTree(preorder, inorder);
    printTree(head);
}

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end){
    static int index = 0;
    if(start >end)  return NULL;
    TreeNode *newNode = new TreeNode(preorder[index++]);
    int dividePoint = find(inorder.begin(), inorder.end(), newNode->val) - inorder.begin();
    newNode->left = solve(preorder, inorder, start, dividePoint-1);
    newNode->right = solve(preorder, inorder, dividePoint+1, end);
    return newNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return solve(preorder, inorder, 0, inorder.size()-1);
}

void printTree(TreeNode *head){
    queue<TreeNode*> q;
    vector<string> result;
    q.push(head);
    while(!q.empty()){
        TreeNode *cur = q.front();
        q.pop();
        if(cur == NULL){
                result.push_back("null");
        }   else{
                result.push_back(to_string(cur->val));
                q.push(cur->left);
                q.push(cur->right);
        }
    }
    while(!result.empty() && result.back() == "null"){
        result.pop_back();
    }
    for(auto num : result)
        cout << num << " ";
}
