/**
 *  Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space.
 * You may not modify the values in the list, only nodes itself can be changed. 
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

class MySolution {
public:
    ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

    	ListNode *p = head;
    	ListNode *q = p->next;
		ListNode *j, *k;

		while (q != NULL) {
			k = q->next;
			q->next = p;
			p->next = k;
			if (p == head) {
				head = q;
			}

			j = p;

			p = k;
			if (p != NULL) {
				q = p->next;
				if (q == NULL) {
					j->next = p;
				} else {
					j->next = q;
				}
			} else {
				q = NULL;
			}
		}

		return head;
    }
};

int main()
{
	//int a[] = {1};
	//int a[] = {1, 2};
	//int a[] = {1, 3, 9, 15};
	int a[] = {1, 3, 9, 5, 7};
	ListNode *h = NULL;

	createList(h, a, sizeof(a) / sizeof(*a));

	print(h);

	MySolution snip;
	ListNode *nh = snip.swapPairs(h);
	
	print(nh);

	release(nh);

	return 0;
}
