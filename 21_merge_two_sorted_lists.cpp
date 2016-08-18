/*
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (l1 == NULL || l2 == NULL) return (l1 == NULL) ? l2 : l1;

		ListNode *p = l1;
		ListNode *q = l2;
		ListNode *k = NULL;
		ListNode *nh = NULL;

		while (p != NULL && q != NULL) {
			if (p->val < q->val) {
				if (nh == NULL) {
					nh = p;
					k = nh;
				} else {
					k->next = p;
					k = k->next;
				}
				p = p->next;
			} else {
				if (nh == NULL) {
					nh = q;
					k = nh;
				} else {
					k->next = q;
					k = k->next;
				}
				q = q->next;
			}
		}

		k->next = (q != NULL) ? q : p;

		return nh;
    }
};

int main()
{
	int a[] = {1, 3, 9, 15};
	int b[] = {2, 5, 10, 14};
	ListNode *l1 = NULL, *l2 = NULL;

	createList(l1, a, sizeof(a) / sizeof(*a));
	createList(l2, b, sizeof(b) / sizeof(*b));

	print(l1);
	print(l2);

	Solution mtsl;
	ListNode *nh = mtsl.mergeTwoLists(l1, l2);
	
	print(nh);

	release(nh);

	return 0;
}
