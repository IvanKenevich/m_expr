/**
 * Created by Ivan on 5/27/2018.
 */
public class ExprTree {
    ExprNode root;
    ExprNode current;

    /**
     * Creates an empty tree
     */
    public ExprTree() {
        current = root = null;
    }

    /**
     * Creates a tree with 1 node
     * @param root root of the tree
     */
    public ExprTree(ExprNode root) {
        current = this.root = root;
    }

    //public ExprTree(ExprTree source) {}

    /**
     * Adopts the current working node
     * @param parent node's new parent
     * @return true on success
     */
    public boolean adoptCurrent(ExprNode parent) {
        return false;
    }

    /**
     * Retrieves the current working node
     * @return pointer to the node
     */
    public ExprNode getCurrent() {
        return null;
    }

    /**
     * Adds a new node at the current working location
     * @param node node to be added
     * @return true on success
     */
    public boolean add(ExprNode node) {
        return false;
    }



    static class ExprNode {
        enum Type {VAL, ADD, SUB, MUL, DIV}

        ExprNode.Type type;
        ExprNode[] children;

        public ExprNode(ExprNode.Type type) {
            this.type = type;
            this.children = new ExprNode[2];
        }

        public ExprNode(ExprNode.Type type, ExprNode ... children) {
            this.type = type;
            this.children = children;
        }

        static int sizeChildren(ExprNode.Type type) {
            switch (type) {
                case VAL: return 1;
                default: return 2;
            }
        }
    }
}
