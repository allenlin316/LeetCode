#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int start, int end);
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder);
void printTree(TreeNode *head);

int main()
{
    int num;
    vector<int> preorder;
    vector<int> postorder;
    while(cin >> num){
        preorder.push_back(num);
        if(cin.get() == '\n') break;
    }
    while(cin >> num){
        postorder.push_back(num);
        if(cin.get() == '\n') break;
    }
    TreeNode *head = constructFromPrePost(preorder, postorder);
    printTree(head);
}

TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int start, int end){
    static int index = 0;
    if(start > end || index >= preorder.size()) return NULL;
    TreeNode *newNode = new TreeNode(preorder[index++]);
    if(start == end)    return newNode;
    int dividePoint = find(postorder.begin(), postorder.end(), preorder[index]) - postorder.begin();
    newNode->left = solve(preorder, postorder, start, dividePoint);
    newNode->right = solve(preorder, postorder, dividePoint+1, end-1);
    return newNode;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    return solve(preorder, postorder, 0, preorder.size()-1);
}

void printTree(TreeNode *head){
    queue<TreeNode*> q;
    vector<string> result;
    q.push(head);
    while(!q.empty()){
        TreeNode *cur = q.front();
        q.pop();
        if(cur == NULL)
            result.push_back("null");
        else{
            result.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    while(!result.empty() && result.back() == "null")
        result.pop_back();
    for(auto num : result)
        cout << num << " ";
}
