/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 */

/**
 * Definition for singly-linked list.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addNth(ListNode *&h, int n, int v);
void addHead(ListNode *&h, int v);
void addTail(ListNode *&h, int v);

void createList(ListNode *&h, int *a, int size)
{
	if (a == NULL || size <= 0)
		return ;

	int i;
	for (i = 0; i < size; i++) {
		addTail(h, a[i]);
	}
}

void addHead(ListNode *&h, int v)
{
	ListNode *n = new ListNode(v);
	if (h == NULL) {
		h = n;
		return;
	}
	n->next = h;
	h = n;
}

void addTail(ListNode *&h, int v)
{
	ListNode *n = new ListNode(v);
	if (h == NULL) {
		h = n;
		return;
	}

	ListNode *p = h;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = n;
}

void addNth(ListNode *&h, int n, int v)
{
	ListNode *p = h;
	int i = 0;

	while (p != NULL && i < n) {
		p = p->next;
		i++;
	}

	if (i != n -1) return;

	ListNode *nn = new ListNode(v);
	nn->next = p->next;
	p->next = nn;
}

void print(ListNode *h)
{
	ListNode *p = h;
	while (p != NULL) {
		std::cout << p->val;
		if (p->next != NULL) {
			std::cout << "->";
		}
		p = p->next;
	}
	std::cout << std::endl;
}

void release(ListNode *h)
{
	if (h == NULL) return;

	ListNode *p = h->next;
	while (p != NULL) {
		h->next = p->next;
		delete p;
		p = h->next;
	}

	delete h;
	h = NULL;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode*& head, int n) {

		if (head == NULL || n <= 0) return NULL;
		if (head->next == NULL && n == 1) {	// list have only 1 element
			delete head;
			head = NULL;
			return NULL;
		}

		ListNode *p = head;
		ListNode *q = head;
		ListNode *k = head;
		int i = 1;

		while (p != NULL && i < n) {
			p = p->next;
			i++;
		}

		if (p == NULL) {	// n > list size
			return NULL;
		}

		while (p->next != NULL) {
			k = q;
			q = q->next;
			p = p->next;
		}

		if (q == head) {	// remove head
			head = head->next;
		} else {
			k->next = q->next;
		}
		q->next = NULL;

		return q;
    }
};

int main()
{
	//int a[] = {1, 2, 3, 4, 5};
	//int a[] = {1};
	int a[] = {1, 2};
	ListNode *h = NULL;
	ListNode *r;

	createList(h, a, sizeof(a) / sizeof(*a));

	std::cout << "before remove Nth element:" << std::endl;
	print(h);

	Solution rnfe;
	r = rnfe.removeNthFromEnd(h, 2);
	if (r != NULL) {
		std::cout << "remove:" << r->val << std::endl;
		delete r;
		r = NULL;
	}

	std::cout << "after remove Nth element:" << std::endl;
	print(h);
	
	release(h);

	return 0;
}
