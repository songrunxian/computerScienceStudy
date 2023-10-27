struct ListNode *reverseList(struct ListNode* head) {
	struct ListNode ret, *p = head , *q;
	ret.next = NULL;
	while(p) {
		q = p->next;
		p->next = ret.next;
		ret.next = p;
		p = q;
	}
	return ret.next;
}
