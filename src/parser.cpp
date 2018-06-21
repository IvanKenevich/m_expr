#include <cmath>
#include "parser.h"


ExprTree* parse(const char* expr_string, int start, int end) {
    ExprTree* result = new ExprTree();

    int i = start;
    while(i <= end) {
        ExprNode* n = NULL;
        i += recognize(expr_string, i, end, n); // tries to recognize something, returns the width of whatever's recognized
        if (n!=NULL) {   // if it is a number or an operator
            //--i;
            result->add(n);  // adds whatever has been recognized
        }
        else {	// if it is a grouping operator
            int group_end = findGroupEnd(expr_string, start);   // grouping starts where i is, find where it ends
            ExprTree * innerTree = parse(expr_string, i, group_end - 1); // recursive call that build an inner tree
            //result->add(innerTree);  // linking that tree to this tree
            i = group_end + 1; 			    // advancing c to the end of tree that has just been built
        }
        //++i;			 // goes to the next character
    }

    return result;
}

/**
 * Recognizes a digit or an operator or a group symbol
 * @param expr_string   string to recognize from
 * @param start         starting index
 * @param end           ending index
 * @param result        pointer to ExprNode that will get built if digit or operator was recognized
 * @return the length of whatever was recognized
 */
int recognize(const char* expr_string, int start, int end, ExprNode* &result) {
    if (expr_string[start] == '(') { // a new group is recognized
        return 1;
    }

    // If it's one of the operators
    else if (expr_string[start] == '+') {
        result = new ExprNode(ExprType::ADD);
        return 1;
    }
    else if (expr_string[start] == '-') {
        result = new ExprNode(ExprType::SUB);
        return 1;
    }
    else if (expr_string[start] == '*') {
        result = new ExprNode(ExprType::MUL);
        return 1;
    }
    else if (expr_string[start] == '/') {
        result = new ExprNode(ExprType::DIV);
        return 1;
    }

    // if it's a digit
    int width = recognizeNum(expr_string, start, end);
    if (width > 0) {
        int value = atoi(expr_string);
        //for (int i = start; i < start + width; i++) {
        //    value += (expr_string[i] - '0') * pow(2, (start+width-1) - i);
        //}
        result = new ExprNode(value);
        return width;
    }

    // if it's anything else, it's bad
    else {
        return 0;
    }
}

/**
 * Finds the length of a number at the beginning of a string
 * @param expr_string   string to find number in
 * @param start         starting index
 * @param end           ending index
 * @return              the length of a number (in characters)
 */
int recognizeNum(const char* expr_string, int start, int end) {
    if (isdigit(expr_string[start])) {
        return 1 + recognizeNum(expr_string, start+1, end);
    }
    else {
        return 0;
    }
}

/**
 * Finds the boundaries of a subexpression
 * @param expr_string string to search in
 * @param start       index of the opening parenthesis
 * @return            index of the closing parenthesis
 */
int findGroupEnd(const char* expr_string, int start) {
	int end = start;
	bool stop = false;
	int parentheses_count = 0;

	while (!stop) {
		if (expr_string[end] == '(') {
			parentheses_count++;
		}
		else if (expr_string[end] == ')') {
			parentheses_count--;
		}
		
		if (parentheses_count == 0) {
			stop = true;
		}
	}

	return end;
}
