using namespace std;

#include <vector>

/**
* Definition of TreeNode: */
 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
 };


class Solution {
public:
	/**
	* @param root: param root: The root of the binary search tree
	* @param k1: An integer
	* @param k2: An integer
	* @return: return: Return all keys that k1<=key<=k2 in ascending order
	*/
	vector<int> searchRange(TreeNode * root, int k1, int k2) {
		// write your code here
		vector<int> r;
		midSearch(root, k1, k2, r);
		return r;
	}

	int midSearch(TreeNode *root, int k1, int k2, vector<int> &ret) {
		if (!root) { return 0; }
		
		if (root->val >= k1 && root->val <= k2) {
			midSearch(root->left, k1, k2, ret);
			ret.push_back(root->val);
			midSearch(root->right, k1, k2, ret);
		}
		else if (root->val < k1) {
			midSearch(root->right, k1, k2, ret);
		}
		else {
			midSearch(root->left, k1, k2, ret);
		}
		return 0;
	}

};

int main() {
	Solution s = Solution();
	return 0;
}