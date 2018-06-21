#include "ExprTree.h"

ExprTree* parse(const char* expr_string, int start, int end);
int recognize(const char* expr_string, int start, int end, ExprNode* &result);
int recognizeNum(const char* expr_string, int start, int end);
int findGroupEnd(const char* expr_string, int start);
