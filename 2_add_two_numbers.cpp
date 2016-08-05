/**
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4), that is 342 + 465
 *
 * Output: 7 -> 0 -> 8, result is 807
 */

/**
 * Definition for singly-linked list.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n = NULL) : val(x), next(n) {}
};

void addNode(ListNode *h, int val)
{
	if (h == NULL) {
		h = new ListNode(val);
		return;
	}

	ListNode *p;
	p = h->next;
	while (p->next) {
		p = p->next;
	}
	ListNode *n = new ListNode(val);
	p->next = n;
}

void clear(ListNode *h)
{
	if (h == NULL) {
		return;
	}

	ListNode *p, *q;
	p = h;
	while (p->next) {
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

void print(ListNode *h)
{
	if (h == NULL) {
		std::cout << "list is empty" << std::endl;
	}
	ListNode *p = h;
	while (p) {
		std::cout << p->val;
		if (p->next != NULL) {
			std::cout << "->";
		}
		p = p->next;
	}
	std::cout << std::endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int j = 0;
		int v;
		int last = 0;

		ListNode *h = NULL, *t = NULL;
    	ListNode *p, *q, *k;
		p = l1;
		q = l2;

		while (p != NULL && q != NULL) {
			v = p->val + q->val;
			if (last) v++;
			last = (v >= 10) ? 1 : 0;
			if (last) v -= 10;

			if (h == NULL) {
				h = new ListNode(v);
				if (h == NULL) {
					return NULL;
				}
				t = h;
			} else {
				ListNode *n = new ListNode(v);
				t->next = n;
				t = n;
			}

			p = p->next;
			q = q->next;
		}

		k = (p != NULL) ? p : q;

		while (k) {
			v = k->val;
			if (last) v++;
			last = (v >= 10) ? 1 : 0;
			if (last) v -= 10;
			ListNode *n = new ListNode(v);
			t->next = n;
			t = n;
			k = k->next;
		}

		if (last) {
			ListNode *n = new ListNode(1);
			t->next = n;
			t = n;
		}

		return h;
    }
};

int main()
{
	ListNode *l13 = new ListNode(9);
	ListNode *l12 = new ListNode(9, l13);
	ListNode *l11 = new ListNode(9, l12);

	ListNode *l23 = new ListNode(9);
	ListNode *l22 = new ListNode(9, l23);
	ListNode *l21 = new ListNode(9, l22);

	print(l11);
	print(l21);

	ListNode *ret;
	Solution atn;
	ret = atn.addTwoNumbers(l11, l21);
	
	print(ret);

	clear(l11);
	clear(l21);
	clear(ret);

	delete l11;
	delete l21;
	delete ret;

	return 0;
}
