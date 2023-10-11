bool hasCycle (struct ListNode *head) {
	struct ListNode *p = head, *q = head;
	if(p == NULL) return false;
	do {
		p = p->next;
		q = q->next;
		if(q == NULL || q->next == NULL) return false;
		q = q->next;
	} while(p != q)
	return true;
}
//两个指针移动速度不同的话，只要有环，一定会相遇
