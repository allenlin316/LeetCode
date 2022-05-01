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

TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end);
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
void printTree(TreeNode *head);

int main()
{
    int num;
    vector<int> inorder;
    vector<int> postorder;
    while(cin >> num){
        inorder.push_back(num);
        if(cin.get() == '\n')   break;
    }
    while(cin >> num){
        postorder.push_back(num);
        if(cin.get() == '\n')   break;
    }
    TreeNode *head = buildTree(inorder, postorder);
    printTree(head);
}

TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end){
    static int index = postorder.size()-1;
    if(start >end)  return NULL;
    TreeNode *newNode = new TreeNode(postorder[index--]);
    int dividePoint = find(inorder.begin(), inorder.end(), newNode->val) - inorder.begin();
    newNode->right = solve(inorder, postorder, dividePoint+1, end);
    newNode->left = solve(inorder, postorder, start, dividePoint-1);
    return newNode;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return solve(inorder, postorder, 0, inorder.size()-1);
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
