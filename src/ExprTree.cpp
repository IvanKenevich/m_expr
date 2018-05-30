#include "ExprTree.h"

ExprNode::ExprNode(ExprType t, int v) {
    left = right = NULL;
    type = t;
    if (type == ExprType::VAL) {
        value = new int;
        *value = v;
    }
    else value = NULL;
}

/**
 * Constructs a value node right away from the argument provided
 */
ExprNode::ExprNode(int v) {
    left = right = NULL;
    type = ExprType::VAL;
    value = new int;
    *value = v;
}

ExprTree::ExprTree() {
    current = root = NULL;
}

int ExprTree::add(ExprNode * node) {
    if (!root) {
        current = root = node;
    }
    else {

    }
}