#include "ExprTree.h"
using namespace std;

int main() {
    cout << "Anyone there?" << endl;
    cin.get();
    return 0;
}

ExprTree * f(char * expr_string) {
	ExprTree * result = new ExprTree();

	char * c = expr_string;
	while(*c!='\0') {
		Node * n = recognize(c); // tries to recognize something, advances c if recognized successfully 
		if (n!=NULL) {   // if it is a number or an operator
			result->add(n);  // adds whatever has been recognized
		}
		else {	// if it is a groupping operator
			char * start = c;                   // the group starts here
			char * end = findGroupEnd(start);   // wherever it ends
			char * sub_expr = substring(expr_string, start, end);  // substring the original expression using the above limits
			ExprTree * innerTree = f(sub_expr); // recursive call that build an inner tree
			result->add(innerTree->getRoot());  // linking that tree to this tree
			c = end; 			    // advancing c to the end of tree that has just been built
		}
		c++;			 // goes to the next character
	}

	return result;
}
