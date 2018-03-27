using namespace std;

#include<string>
#include<queue>

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

		if (data[pos] == ',') { pos++; }
		if (data[pos] == '\0') { return NULL; }

		if (data[pos] == '#') {
			pos++;
			return NULL;
		}		

		int nownum = 0;
		while (data[pos] != ',' && data[pos]!= '\0') {
			nownum = (nownum * 10 ) + (data[pos] - '0');
			pos++;
		}

		TreeNode *node = new TreeNode(nownum);
		node->left = deTree(data, pos);
		node->right = deTree(data, pos);
		return node;
	}

};

class Solution2
{
	/* use BFS to solve */
private :
	queue<int> que;

public:
	unsigned int serializtation(string &src) {
		if (src.size() <= 0) {
			return -1;
		}
		vector<string> nodelist;
		parseString(src, nodelist);
		return 0;
	}

private:
	/* parse all information into vector without determin char:',' */
	unsigned int parseString(string &input, vector<string> &output) {
		if (input.size() <= 0) { return 0; }
		int pos = 0, level = 1;

		while (pos < input.size() && input[pos] != '\0') {			
			unsigned int elemCnt = 0;
			for (int i = 0; i < level && input[pos] != '\0'; i++) {
				string stmp="";
				while (input[pos] != ',' && input[pos] != '\0') {
					stmp += input[pos];
					pos++;
				}
				output.push_back(stmp);
				if (stmp.compare(string("#"))) { elemCnt++; }
				pos++;
			}
			level = 2 * elemCnt;
		}
		return 0;
	}
};

int main() {
	//Solution s = Solution();
	string sin = "12,#,32,34,#,#,45,#,#";
	//TreeNode *t = s.deserialize(sin);	
	Solution2 s2 = Solution2();
	s2.serializtation(sin);
	return 0;
}