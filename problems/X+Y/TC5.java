public class TC5 {
    public static void main(String[] args) {
        String x = "1-i";
        String y = "i";

        String res = "1";

        Solution s = new Solution();
        String ans = s.solve(x, y);

        assert ans.equals(res) : ans;

    }
}
