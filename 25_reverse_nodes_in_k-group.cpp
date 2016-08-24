/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
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

ListNode *reverse(ListNode *beg, ListNode *end)
{
    if (beg == NULL) return NULL;
    if (beg == end) return beg;
    ListNode *p = beg;
    ListNode *q = p->next;
    ListNode *k;
    p->next = NULL;
    while (q != NULL && p != end) {
        k = q->next;
        q->next = p;
        p = q;
        q = k;
    }
    return p;
}

class MySolution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *b = NULL, *e = NULL;
        ListNode *j, *t;

        int i = 0;
        while (1) {
            while (q != NULL && i < k - 2) {
                q = q->next;
                i++;
            }

            if (q == NULL) {
				b->next = p;
 				return head;
			}

			j = q->next;

            t = reverse(p, q);
			print(t);

			if (b == NULL) {
            	b = p;
            	e = q;
			} else {
				b->next = t;
				b = p;
			}

			if (b == head) {
				head = t;
			}

			p = j;
			if (p == NULL) { // list.size() % k = 0
				break;
			} else {
				q = p->next;
			}

            i = 0;
        }

        return head;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *h = NULL;

    createList(h, a, sizeof(a) / sizeof(*a));

    print(h);

    MySolution rkg;
    ListNode *nh = rkg.reverseKGroup(h, 3);

    print(nh);

    release(nh);

    return 0;
}
