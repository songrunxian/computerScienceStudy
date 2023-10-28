struct Stack {
	char *val;
	int p, maxSize;
};
void initStack(struct Stack *s, int maxSize) {
	s->val = malloc(maxSize);
	s->p = 0;
}
bool emptyStack(struct Stack *s) {
	return !(s->p)
}
void pushStack(struct Stack *s, char c) {
	s->val[s->p++] = c;
}
void popStack(struct Stack *s) {
	--(s->p);
}
char seekStack(struct Stack *s) {
	return s->val[s->p-1];
}
bool isValid(char *s) {
	struct Stack stack;
	int len = strlen(s);
	initStack(&stack, len);
	for(int i = 0; i < len; i++) {
		switch(s[i]) {
			case '(':
			case '[':
			case '{':
				pushStack(&stack, s[i]);
				break;
			case ')':
				if(emptyStack(&stack)) return false;
				if(seekStack(&stack) != '(') return false;
				popStack(&stack);
				break;
			case ']':
				if(emptyStack(&stack)) return false;
				if(seekStack(&stack) != '[') return false;
				popStack(&stack);
				break;
			case '}':
				if(emptyStack(&stack)) return false;
				if(seekStack(&stack) != '{') return false;
				popStack(&stack);
				break;
		}
	}
	return emptyStack(&stack);
}
