struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *p = head, *q = head;
	while(q) {
		p = p->next;
		q = q->next;
		if(q == NULL) return NULL;
		q = q->next;
		if(p == q) break;
	}
	if(q == NULL) return NULL;
	q = head;
	while(p != q) {
		p = p->next;
		q = q->next;
	}
	return p;
}
