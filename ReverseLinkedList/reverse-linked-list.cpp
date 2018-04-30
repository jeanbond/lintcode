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
		// ������õ�������������ӵķ�ʽʵ�֣����headָ���Ϊnull���������head������Ϊ���ʹ�ã�
		// �����Ҫ��head��Ϊ���ʹ�ã���ô��Ҫ�ں����ڲ�����һ�£�head=dump��
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
	cout << "����������������е㸴�ӣ�һ����ͨ��lint����������Ͳ�д���ԣ�" << endl;
	cout << "����Ե�����Ľ����ͷ�ת���κ����ʣ��ο���ַΪ��https://blog.csdn.net/fx677588/article/details/72357389" << endl;
	system("pause");
	return 0;
}


