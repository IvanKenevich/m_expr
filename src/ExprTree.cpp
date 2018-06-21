#include "ExprTree.h"

ExprNode::ExprNode(ExprType t) {
    left = right = NULL;
    type = t;
    value = NULL;
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

bool ExprNode::isHigher(const ExprNode * currentParent) const {
		if (type == ExprType::VAL) return false; // anything is higher than a value node
		else if ((type == ExprType::ADD || type == ExprType::SUB) &&
		(currentParent->type == ExprType::MUL || currentParent->type == ExprType::DIV))
			return false;
		else return true;
}

// ============ END NODE. BEGIN TREE ===========================

ExprTree::ExprTree() {
    currentParent = current = root = NULL;
}

int ExprTree::add(ExprNode * node) {
    if (!root) {
        currentParent = current = root = node;
    }
    else {
		if (node->isHigher(currentParent)) {

		}
		else {

		}
    }
}
