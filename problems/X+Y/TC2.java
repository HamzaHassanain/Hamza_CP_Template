public class TC2 {
    public static void main(String[] args) {
        String x = "6";
        String y = "-7";

        String res = "-1";

        Solution s = new Solution();
        String ans = s.solve(x, y);

        assert ans.equals(res) : ans;

    }
}
