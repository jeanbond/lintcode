using namespace std;

#include<string>
#include<sstream>
#include<vector>


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
		ostringstream out;
		serials(root, out);
		return out.str();
	}
private:
	void serials(TreeNode *node, ostream &out) {
		if (node) {
			out << node->val << ",";
			serials(node->left, out);
			serials(node->right, out);
		}
		else {
			out << "#";
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
		return NULL;
	}
private:
	TreeNode * deserials(istringstream &in) {
			return NULL;
		
	}
	int split(string &input, vector<string> &out, char c) {
		if (!input.length()) { return -1; }
		const char *cin = input.c_str();
	
		return 0;
	}

};

int main() {
	Solution s = Solution();
	string sin = "1,#,2";
	s.deserialize(sin);
	return 0;
}