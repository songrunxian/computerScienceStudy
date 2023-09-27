//手动模拟，摆弄指针，即可理解
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode *p, *q, ret;
	ret.next = head;
	p = &ret;
	q = head;
	while(q && q->next) {
		p->next = q->next;
		q->next = p->next->next;
		p->next->next = q;
		p = q;
		q = q->next;
	}
	return ret.next;
}
