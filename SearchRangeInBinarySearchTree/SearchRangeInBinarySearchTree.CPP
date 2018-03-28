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
		// 考虑到使用递归解决，采用子函数自递归比较合适
		midSearch(root, k1, k2, r);
		return r;
	}

	int midSearch(TreeNode *root, int k1, int k2, vector<int> &ret) {
		if (!root) { return 0; }
		
		//满足要求的元素
		if (root->val >= k1 && root->val <= k2) {
			midSearch(root->left, k1, k2, ret);
			ret.push_back(root->val);
			midSearch(root->right, k1, k2, ret);
		}
		else if (root->val < k1) {
			midSearch(root->right, k1, k2, ret); // 比K1大的右子树中有部分元素可能满足要求，递归进入并判断。
		}
		else {
			midSearch(root->left, k1, k2, ret);	 // 比K2小的左子树中有部分元素可能满足要求，递归进入并判断。
		}
		return 0;
	}

};

int main() {
	Solution s = Solution();
	return 0;
}