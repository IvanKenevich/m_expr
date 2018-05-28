package practice;

/**
 * Created by Ivan on 5/27/2018.
 */
public class BST {
    private static class Node {
        private int data;
        private Node left, right;

        Node() {
            this.data = -1;
            right = left = null;
        }

        Node(int data) {
           this.data = data;
           right = left = null;
        }
    }

    private Node root;

    BST() {
        root = null;
    }

    public boolean add(int i) {
        if (root == null) {
            root = new Node(i);
            return true;
        }
        else return add(root, i);
    }

    public void add(int ... values) {
        for (int i : values) {
            add(i);
        }
    }

    private boolean add(Node root, int i) {
        if (root == null) {
            root = new Node(i);
            return true;
        }
        if (i >= root.data) return add(root.right, i);
        else return add(root.left, i);
    }

    public void print() {
        if (root == null) System.out.println("The tree is empty");
        else print(root);
    }

    private void print(Node root) {
        if (root != null) {
            print(root.left);
            System.out.println(" " + root.data + " ");
            print(root.right);
        }
    }
}
