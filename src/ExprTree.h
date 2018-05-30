#include <iostream>

enum ExprType {ADD, SUB, MUL, DIV, VAL};

struct ExprNode {
    ExprNode * left;
    ExprNode * right;
    ExprType type;
    int * value;

    ExprNode(ExprType type, int value);
    ExprNode(int value);
    ~ExprNode();
};

class ExprTree {
public:
    ExprTree();
    ~ExprTree();

    int add(ExprNode * node);
    int evaluate(void);

private:
    /**
     * First make a temp pointer to child
     * Set child pointer to parent
     * Set parent's left ptr to child
     * move current
     */
    int adopt(ExprNode * &child, ExprNode * parent);

    ExprNode * root;
    ExprNode *current;
};
