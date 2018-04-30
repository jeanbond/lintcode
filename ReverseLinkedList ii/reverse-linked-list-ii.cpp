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
	 两个函数运行都OK，但是有细微差别，后续补上注释
	 */
	 ListNode * reverseBetween(ListNode * head, int m, int n) {
		 if (!head->next) {return head;}
		 // 必须使用一个头结点dump，所有翻转好之后的数据都放在这个结点的后面；
		 // 不推荐使用new分配，new会导致内存泄漏；
		 // 因为我们把操作的head当做一个子串，避免我们从第一个元素开始翻转的时候没有pre指针；
		 ListNode dump(0);
		 dump.next = head;
		 ListNode *pre = &dump, *aft, *mth, *nth;
		 //找到各自的位置：
		 // pre、mth、nth 、after，标记2个分段点的四个前后位置；
		 for (int i = 1; i < n; i++) {
			 if (i == m - 1) pre = head;
			 head = head->next;
		 }
		 mth = pre->next;
		 nth = head;
		 aft = nth->next;

		 // 截断中间区间，便于后续做区间翻转；
		 nth->next = NULL;

		 nth = mth; // 使用nth来标记最后结束的位置，便于翻转之后连接；
		 ListNode *out=NULL;
		 // 区间翻转，需要注意的是，这里翻转之后，mth为空，我们必须重新找到被翻转区间的结束位置；
		 while (mth) {
			 ListNode *next = mth->next;
			 mth->next = out;
			 out = mth;
			 mth = next;
		 }
		 // 重新连接断开的两个位置；
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
		 // 这里需要特别注意，上面一个函数中未使用函数操作方式，这里使用的函数操作，有差别；
		 // 使用函数操作之后 mth指针中存储的地址未改变，他还是指向原来的位置，但是原来被指向的地址内的数据内容已经被改变了
		 // 采用指针作为函数的入参的时候，我们只能修改指针指向的地址中数据，但是不能改变入参指针指向的地址；
		 // 所以我们在运行完毕之后，mth不为空，同时完成mth-nth区间的翻转，mth指向的是未翻转之前的第一个元素，翻转之后
		 // 就是区间最后一个元素，所以我们可以用它来连接后面的链表；
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