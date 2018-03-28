using namespace std;

#include<string>
#include<queue>
#include<sstream>

class TreeNode {
public:
     int val;
     TreeNode *left, *right;

     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
	 TreeNode(string val) {
		 stringstream ss;
		 ss << val;
		 int va = 0;
		 ss >> va;
		 this->val = va;
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
		//when we use a recursion func,
		//we must have at least one return path.
		if (node) {
			str += (to_string(node->val) + ",");
			serials(node->left, str);
			serials(node->right, str);
		}
		else {
			str += "#,";
			return;
		}
		// clean the last , mark in string list.
		str[str.size() - 1] = '\0';
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
		// to identify the global location in string data.
		int pos = 0;
		return deTree(data, pos);
	}

	TreeNode* deTree(string &data, int &pos) {

		//operate the special treatment.
		if (data[pos] == ',') { pos++; }
		if (data[pos] == '\0') { return NULL; }

		if (data[pos] == '#') {
			pos++;
			return NULL;
		}		

		// calculate multibit data.
		//caution: convert char to int number.
		int nownum = 0;
		while (data[pos] != ',' && data[pos]!= '\0') {
			nownum = (nownum * 10 ) + (data[pos] - '0');
			pos++;
		}

		// this recursion seems some special.
		// no return swith, use the terminal return to end it;
		// so we must have a retrun at the end;
		TreeNode *node = new TreeNode(nownum);
		node->left = deTree(data, pos);
		node->right = deTree(data, pos);
		return node;
	}

};

/* someting wrong with this Solution2 class */
class Solution2
{
	/* use BFS to solve */
private :
	queue<int> que;

public:
	TreeNode* serializtation(string &src) {
		int rc = 0;
		if (src.size() <= 0) {
			return NULL;
		}
		vector<string> nodelist;
		rc = parseString(src, nodelist);
		if (rc) { return NULL; }

		return serialTree(nodelist);
	}

private:
	/* 二叉树的非递归构造方法实现：
		该函数有问题，未能实现功能，如果想测试代码，请直接使用Solution类解决。
		Solution类已经通过lc测试，没问题； */
	TreeNode * serialTree(vector<string> &in) {
		TreeNode *root = new TreeNode(in[0]) , *pstPre = NULL;
		queue<string> qu;
		pstPre = root;
		int pos = 0;

		qu.push(in[pos]);
	
		while (!qu.empty()) {
			int len = qu.size();
			for (int i = 0; i < len; i++) {
				if (in[pos + 1] != "#") { qu.push(in[pos + 1]); }
				if (in[pos + 2] != "#") { qu.push(in[pos + 2]); }
			}

			pos++;
		}
		return root;
	}

	/* parse all information into vector without determin char:',' */
	unsigned int parseString(string &input, vector<string> &output) {
		if (input.size() <= 0) { return 0; }
		int pos = 0, level = 1;

		while (pos < (int)input.size() && input[pos] != '\0') {			
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