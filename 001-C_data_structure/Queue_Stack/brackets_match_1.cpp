bool isValid(char *s) {
	int32_t lnum = 0, rnum = 0;
	int32_t len = strlen(s);
	for(int32_t i = 0; i < len; i++) {
		switch(s[i]) {
			case '(': ++lnum;break;
			case ')': ++rnum;break;
			default : return false;
		}
		if(lnum >= rnum) continue;
		return false;
	}
	return lnum == rnum;
}
