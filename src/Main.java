public class Main {
    private final static String
            digits = "0123456789",
            operators = "+-/*";


    public static void main(String[] args) {
        System.out.println(hasNum("3a2"));
    }

    private static boolean isNum(String s) {
        if (s.length()==1) {
            return digits.indexOf(s.charAt(0)) >= 0;
        }
        else if (digits.indexOf(s.charAt(0)) >= 0)
            return isNum(s.substring(1));
        else
            return false;
    }

    /**
     * Finds the first number within a string
     * @param s the string to be tested
     * @return the index into s where the last digit of the number is located
     *         or -1 if string doesn't contain a number at the beginning
     */
    private static int hasNum(String s) {
        if (s.length()==1) {
            if(digits.indexOf(s.charAt(0)) >= 0) return 0;
            else return -1;
        }
        else if (digits.indexOf(s.charAt(0)) >= 0) {
            return 1 + hasNum(s.substring(1));
        }
        else return -1;
    }
}
