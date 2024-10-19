public class TC6 {
    public static void main(String[] args) {
        String x = "10+i";
        String y = "5";

        String res = "15+i";

        Solution s = new Solution();
        String ans = s.solve(x, y);

        assert ans.equals(res) : ans;

    }
}
