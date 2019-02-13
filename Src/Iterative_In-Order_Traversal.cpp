#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodes;
		TreeNode* cur = root;
		vector<int> inorder;
		while (cur != nullptr || !nodes.empty()) {
			while (cur != nullptr) {
				nodes.push(cur);
				cur = cur->left;
			}
			cur = nodes.top();
			nodes.pop();
			inorder.push_back(cur->val);
			cur = cur->right;
		}
		return inorder;
	}
};