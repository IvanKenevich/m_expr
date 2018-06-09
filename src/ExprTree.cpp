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

ExprNode::isHigher(const Node * currentParent) const {
		if (type == ExprType::VAL) return false; // if this is a value node, it is lower
		else if ((type == ExprType::ADD || type == ExprType::SUB) &&
		(currentParent->type == ExprType::MUL || currentParent->type == ExprType::DIV)) 
			return false;
}

// ============ END NODE BEGIN TREE ===========================

ExprTree::ExprTree() {
    currentParent = current = root = NULL;
}

int ExprTree::add(ExprNode * node) {
    if (!root) {
        current_parent = current = root = node;
    }
    else {
		if (node.isHigher(currentParent)) {

		}
		else {

		}
    }
}
