public class TC4 {
    public static void main(String[] args) {
        String x = "5i";
        String y = "5-4i";

        String res = "5+i";

        Solution s = new Solution();
        String ans = s.solve(x, y);

        assert ans.equals(res) : ans;

    }
}
