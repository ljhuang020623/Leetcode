#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

private:
    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left_h = dfs(node->left);
        if (left_h == -1) return -1;

        int right_h = dfs(node->right);
        if (right_h == -1) return -1;

        if (abs(right_h - left_h) > 1) return -1;


        return max(right_h, left_h) + 1;
    }
};