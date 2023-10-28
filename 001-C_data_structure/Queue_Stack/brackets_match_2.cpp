bool isValid(char *s) {
	int32_t lnum = 0;
	int32_t len = strlen(s);
	for(int32_t i = 0; i < len; i++) {
		switch(s[i]) {
			case '(' : ++lnum; break;
			case ')' : --lnum; break;
			default : return false;
		}
		if(lnum >= 0) continue;
		return false;
	}
	return lnum == 0;
}
