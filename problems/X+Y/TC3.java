public class TC3 {
    public static void main(String[] args) {
        String x = "i";
        String y = "-2i";

        String res = "-i";

        Solution s = new Solution();
        String ans = s.solve(x, y);

        assert ans.equals(res) : ans;

    }
}
