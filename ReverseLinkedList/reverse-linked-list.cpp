using namespace std;
#include<iostream>
typedef struct str_linklist_tag{
	int data;
	struct str_linklist_tag *next;
}ListNode;

class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: The new head of reversed linked list.
	*/
	ListNode *reverse(ListNode *head) {
		// 这里采用的是逐个向上增加的方式实现，最后head指针会为null，所以最后head不能作为输出使用；
		// 如果需要将head作为输出使用，那么需要在函数内部处理一下，head=dump；
		ListNode *dummy = NULL;
		while (head != NULL) {
			ListNode *temp = head->next;
			head->next = dummy;
			dummy = head;
			head = temp;
		}
		return dummy;
	}

	ListNode *ReverseRecursor(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *newP = ReverseRecursor(head->next);
		head->next->next = head;
		head->next = NULL;
		return newP;
	}
};

int main() {
	cout << "这个测试用例构造有点复杂，一次性通过lint；所以在这就不写测试；" << endl;
	cout << "如果对单链表的交换和翻转有任何疑问，参考地址为：https://blog.csdn.net/fx677588/article/details/72357389" << endl;
	system("pause");
	return 0;
}


