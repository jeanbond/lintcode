using namespace std;

#include<iostream>
#include<queue>

#define LEAF_NODE_FLAG			('#')
#define OK						(0)
#define ERROR					(-1)
#define MAX(a,b)				((a>b)?a:b)

typedef struct _node_tree{
	char data;
	struct _node_tree  *left, *right;
} LNode;

class ListTree {
private:
	LNode * root;
	ListTree() {
		this->root = NULL;
		this->root->left = NULL;
		this->root->right = NULL;
	}

	int createTree(LNode *pNode) {
		char ch;
		cout << "Input to create Tree ..." << endl;
		cin >> ch;
		if (ch == LEAF_NODE_FLAG) {
			return NULL;
		}else{
			LNode *node = new LNode();
			node->data = ch;
			createTree(node->left);
			createTree(node->right);
		}
		return OK;
	}

	int cleanTree(LNode *root) {
		if (!&root) {return OK;}
		
		cleanTree(root->left);
		cleanTree(root->right);
		delete &root;
		root = NULL;
		return OK;
	}

	int getHight(LNode *root) {
		if (root) {
			return MAX(getHight(root->left), getHight(root->right)) + 1;
		}
		else {
			return 0;
		}		
	}

	int getTreeNodeNumber(LNode *root) {
		if (root) {
			return getTreeNodeNumber(root->left) + getTreeNodeNumber(root->right) + 1;
		}
		else {
			return 0;
		}
	}

	int preShow(LNode *root) {
		if (!root) {
			return OK;
		}
		cout << root->data << " ";
		preShow(root->left);
		preShow(root->right);
		return OK;
	}

	int midShow(LNode *root) {
		if (!root) {
			return OK;
		}
		midShow(root->left);
		cout << root->data << " ";
		midShow(root->right);
		return OK;
	}
	int aftShow(LNode *root) {
		if (!root) {
			return OK;
		}
		aftShow(root->left);
		aftShow(root->right);
		cout << root->data << " ";
		return OK;
	}

	int levelShow(LNode *root) {
		if (!root) { return OK; }
		queue<LNode> qu;
		qu.push(*root);

		while (!qu.empty()) {
			LNode *pTmp = &qu.front();
			cout << pTmp->data << " ";
			qu.pop();
			
			if (pTmp->left) { qu.push(*(pTmp->left)); }
			else if (pTmp->right) { qu.push(*(pTmp->right)); }
		}
		return OK;
	}
};

int main() {
	system("pause");
	return 0;
}