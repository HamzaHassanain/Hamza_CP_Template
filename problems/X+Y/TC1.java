public class TC1 {
    public static void main(String[] args) {
        String x = "-i";
        String y = "10";

        String res = "10-i";

        Solution s = new Solution();
        String ans = s.solve(x, y);

        assert ans.equals(res) : ans;

    }
}
