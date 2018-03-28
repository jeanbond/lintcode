using namespace std;

#include <iostream> 

#define ERROR				(-1)
#define OK					(0)
#define NODE_INVALID_VALUE	(~0)
#define LEFT_DIRECT			(0)
#define RIGHT_DIRECT		(1)
#define CALC_LEFT_LOC(loc)	((2*loc)+1)
#define CALC_RIGHT_LOC(loc)	((2*loc)+2)


class ArrTree
{
private:
	int m_arrTreeSize;
	int *m_arrTreeRoot;

public:
	ArrTree() {
		this->m_arrTreeSize = 0;
		this->m_arrTreeSize = NULL;
	}
	ArrTree(int size){
		this->m_arrTreeSize = size;
		this->m_arrTreeRoot = new int[this->m_arrTreeSize];
		for (int i = 0; i < this->m_arrTreeSize; i++) {
			this->m_arrTreeRoot[i] = NODE_INVALID_VALUE;
		}
	}
	ArrTree(int size, int *pRoot) {
		this->m_arrTreeSize = size;
		this->m_arrTreeRoot = new int[this->m_arrTreeSize];
		for (int i = 0; i < this->m_arrTreeSize; i++) {
			this->m_arrTreeRoot[i] = NODE_INVALID_VALUE;
		}
		this->m_arrTreeRoot[0] = *pRoot;
	}

	~ArrTree() {
		if (this->m_arrTreeSize) { delete[] m_arrTreeRoot; this->m_arrTreeRoot = NULL; }
		else { this->m_arrTreeRoot = NULL; }
		this->m_arrTreeSize = 0;
	}

	int *searchNode(int nodeLocation) {
		if (nodeLocation > this->m_arrTreeSize || nodeLocation < 0) { return NULL; }
		if (this->m_arrTreeRoot[nodeLocation] == NODE_INVALID_VALUE){ return NULL; }
		return &this->m_arrTreeRoot[nodeLocation];
	}

	bool isEmpty() {
		if (this->m_arrTreeSize == 0) { return true; }
		if (this->m_arrTreeRoot[0] == NODE_INVALID_VALUE) { return true; }
		return false;
	}

	int addNode(int nodeIdx, int direction, int *pNode) {
		if (nodeIdx > this->m_arrTreeSize || nodeIdx < 0) { return ERROR; }
		//if (this->isEmpty()) { return ERROR; }

		if (direction == LEFT_DIRECT) {
			if (CALC_LEFT_LOC(nodeIdx) >= this->m_arrTreeSize) { return ERROR; }
			if (this->m_arrTreeRoot[CALC_LEFT_LOC(nodeIdx)] != NODE_INVALID_VALUE) {
				return ERROR;
			}
			this->m_arrTreeRoot[CALC_LEFT_LOC(nodeIdx)] = *pNode;
		}
		else if (direction == RIGHT_DIRECT) {
			if (CALC_RIGHT_LOC(nodeIdx) >= this->m_arrTreeSize) { return ERROR; }
			if (this->m_arrTreeRoot[CALC_RIGHT_LOC(nodeIdx)] != NODE_INVALID_VALUE) {
				return ERROR;
			}
			this->m_arrTreeRoot[CALC_RIGHT_LOC(nodeIdx)] = *pNode;
		}else{
			return ERROR;
		}

		return OK;
	}

	int deleteNode(int nodeIdx, int *pNode) {
		if (nodeIdx <= 0 || nodeIdx >= this->m_arrTreeSize) {
			return ERROR;
		}
		if (this->isEmpty()) { return ERROR; }

		*pNode = this->m_arrTreeRoot[nodeIdx];
		this->m_arrTreeRoot[nodeIdx] = 0;

		return OK;
	}

	void traverseTree() {
		if (isEmpty()) { cout << "Tree is empty! Tree traverse end !" << endl; }
		for (int i = 0; i < m_arrTreeSize; i++) {
			cout.flags(ios::hex);
			cout <<"0x" << (unsigned int)this->m_arrTreeRoot[i] << " ";
		}
		return;
	}
};

int main() {

	int root = 1;
	ArrTree *p = new ArrTree(7, &root);

	int node[] = { 2, 45, 5, 7, 23 };

	p->addNode(0, 0, &node[0]);//根的左节点  
	p->addNode(0, 1, &node[1]);//根的右节点  

	p->addNode(2, 0, &node[2]);//根的右节点的左节点  
	p->addNode(2, 1, &node[3]);    //根的右节点的右节点  

	p->traverseTree();

	cout << "\n根的右节点的右节点：" << *(p->searchNode(6)) << endl;

	int t = 0;
	p->deleteNode(6, &t);
	cout << "\n删除的节点：" << t << endl;
	cout << "\n再次遍历：" << endl;
	p->traverseTree();

	p->~ArrTree();

	system("pause");
	return 0;
}