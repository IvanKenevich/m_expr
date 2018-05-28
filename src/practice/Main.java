package practice;

/**
 * Created by Ivan on 5/27/2018.
 */
public class Main {
    public static void main(String[] args) {
        BST tree = new BST();
        tree.print();
        //tree.add(10,5,12,11,13);
        tree.add(10);
        tree.add(5);
        tree.add(12);
        tree.print();
    }
}
