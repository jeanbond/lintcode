using namespace std;
#include<string>

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
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode * root) {
		// write your code here
		string s = "";
		serials(root, s);
		return s;
	}
private:
	void serials(TreeNode *node, string &str) {
		if (node) {
			str += (to_string(node->val) + ",");
			serials(node->left, str);
			serials(node->right, str);
		}
		else {
			str += "#";
			return;
		}
		return;
	}

public:

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode * deserialize(string &data) {
		int pos = 0;
		return deTree(data, pos);
	}

	TreeNode* deTree(string &data, int &pos) {
		if (data[pos] == '#') {
			pos ++;
			return NULL;
		}

		int nownum = 0;
		while (data[pos] != ',') {
			nownum = (nownum * 10) + (nownum - '0');
			pos++;
		}
		pos++;

		TreeNode *node = new TreeNode(nownum);
		node->left = deTree(data, pos);
		node->right = deTree(data, pos);
		return node;
	}

};

int main() {
	Solution s = Solution();
	string sin = "1,#,2";
	TreeNode *t = s.deserialize(sin);	
	return 0;
}