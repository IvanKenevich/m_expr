

ExprTree* parse(char* expr_string) {

}

ExprNode* recognize(char* start_char) {

}

char* findGroupEnd(char* start) {
	char* c = start;
	bool stop = false;
	int parentheses_count = 0;

	while (stop != true) {
		if (*c == '(') {
			parentheses_count++;
		}
		else if (*c ==")") {
			parenthese_count--;
		}
		
		if (parentheses_count == 0) {
			stop = true;
		}
	}

	return c;
}
