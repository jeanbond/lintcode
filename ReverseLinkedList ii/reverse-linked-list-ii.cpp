using namespace std;
#include<iostream>
#include<vector>


 class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
        this->val = val;
        this->next = NULL;
     }
 };


 class Solution {
 public:
	 /**
	 * @param head: ListNode head is the head of the linked list
	 * @param m: An integer
	 * @param n: An integer
	 * @return: The head of the reversed ListNode
	 �����������ж�OK��������ϸ΢��𣬺�������ע��
	 */
	 ListNode * reverseBetween(ListNode * head, int m, int n) {
		 if (!head->next) {return head;}
		 // ����ʹ��һ��ͷ���dump�����з�ת��֮������ݶ�����������ĺ��棻
		 // ���Ƽ�ʹ��new���䣬new�ᵼ���ڴ�й©��
		 // ��Ϊ���ǰѲ�����head����һ���Ӵ����������Ǵӵ�һ��Ԫ�ؿ�ʼ��ת��ʱ��û��preָ�룻
		 ListNode dump(0);
		 dump.next = head;
		 ListNode *pre = &dump, *aft, *mth, *nth;
		 //�ҵ����Ե�λ�ã�
		 // pre��mth��nth ��after�����2���ֶε���ĸ�ǰ��λ�ã�
		 for (int i = 1; i < n; i++) {
			 if (i == m - 1) pre = head;
			 head = head->next;
		 }
		 mth = pre->next;
		 nth = head;
		 aft = nth->next;

		 // �ض��м����䣬���ں��������䷭ת��
		 nth->next = NULL;

		 nth = mth; // ʹ��nth�������������λ�ã����ڷ�ת֮�����ӣ�
		 ListNode *out=NULL;
		 // ���䷭ת����Ҫע����ǣ����﷭ת֮��mthΪ�գ����Ǳ��������ҵ�����ת����Ľ���λ�ã�
		 while (mth) {
			 ListNode *next = mth->next;
			 mth->next = out;
			 out = mth;
			 mth = next;
		 }
		 // �������ӶϿ�������λ�ã�
		 pre->next = out;
		 nth->next = aft;
		 return dump.next;
	 }

	 ListNode *reverseBetween1(ListNode *head, int m, int n) {
		 if (!head->next) return head;

		 ListNode dummy(0); dummy.next = head;
		 ListNode *mth, *nth, *mth_prev = &dummy, *nth_next;
		 for (int i = 1; i < n; ++i) {
			 if (i == m - 1) mth_prev = head;
			 head = head->next;
		 }
		 mth = mth_prev->next;
		 nth = head;
		 nth_next = nth->next;

		 nth->next = NULL;
		 // ������Ҫ�ر�ע�⣬����һ��������δʹ�ú���������ʽ������ʹ�õĺ����������в��
		 // ʹ�ú�������֮�� mthָ���д洢�ĵ�ַδ�ı䣬������ָ��ԭ����λ�ã�����ԭ����ָ��ĵ�ַ�ڵ����������Ѿ����ı���
		 // ����ָ����Ϊ��������ε�ʱ������ֻ���޸�ָ��ָ��ĵ�ַ�����ݣ����ǲ��ܸı����ָ��ָ��ĵ�ַ��
		 // �����������������֮��mth��Ϊ�գ�ͬʱ���mth-nth����ķ�ת��mthָ�����δ��ת֮ǰ�ĵ�һ��Ԫ�أ���ת֮��
		 // �����������һ��Ԫ�أ��������ǿ������������Ӻ��������
		 reverse_list(mth);
		 show(mth);
		 mth_prev->next = nth;
		 mth->next = nth_next;

		 return dummy.next;
	 }

	 void reverse_list(ListNode *head) {
		 ListNode *prev = NULL;
		 while (head) {
			 ListNode *next = head->next;
			 head->next = prev;
			 prev = head;
			 head = next;
		 }
	 }

 private:
	 void show(ListNode *head) {
		 ListNode *tmp = head;
		 if (head == NULL) cout << "null";
		 while (tmp != NULL) {
			 cout << tmp->val << "->";
			 tmp = tmp->next;
		 }
		 cout << endl;
	 }
 };

int main() {
	ListNode head(3760);
	ListNode a1(2881);
	head.next = &a1;
	ListNode a2(7595);
	a1.next = &a2;
	ListNode a3(3904);
	a2.next = &a3;
	ListNode a4(5069);
	a3.next = &a4;
	ListNode a5(4421);
	a4.next = &a5;
	ListNode a6(8560);
	a5.next = &a6;
	ListNode a7(8879);
	a6.next = &a7;
	ListNode a8(8488);
	a7.next = &a8;
	ListNode a9(5040);
	a8.next = &a9;
	ListNode a10(5792);
	a9.next = &a10;
	ListNode a11(56);
	a10.next = &a11;
	ListNode a12(1007);
	a11.next = &a12;
	ListNode a13(2270);
	a12.next = &a13;
	ListNode a14(3403);
	a13.next = &a14;
	ListNode a15(6062);
	a14.next = &a15;

	Solution s = Solution();
	s.reverseBetween1(&head,2,7);
	return 0;
}