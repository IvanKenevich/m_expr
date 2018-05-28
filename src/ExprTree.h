#include <iostream>

enum class ExprType {ADD, SUB, MUL, DIV, VAL};

struct ExprNode {
    ExprNode * left;
    ExprNode * right;
    ExprType type;
    int * value;

    ExprNode(ExprType type) {
        left = right = NULL;
        // do things based on type
    }

    ~ExprNode() {
        // set pointers to null and delete data
    }
};

class ExprTree {
public:
    ExprTree();
    ~ExprTree();
    /**
     * First make a temp pointer to child
     * Set child pointer to parent
     * Set parent's left ptr to child
     */
    int adopt(ExprNode * &child, ExprNode * parent);

    int addRightChild()

private:
    ExprNode root, current;
};
