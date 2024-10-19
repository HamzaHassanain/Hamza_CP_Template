
public class TC2 {
    public static void main(String[] args) {

        long n = 5, w = 1;
        String[] grid = new String[] {
                ".....",
                "#####",
                "#####",
                "...#.",
                "P.##."
        };

        String[] ans = new String[] {
                ".....",
                "#####",
                "#####",
                "PPP#.",
                "PP##."
        };

        Solution s = new Solution();
        String[] res = s.solve(n, w, grid);

        assert res.length == ans.length;

        for (int i = 0; i < res.length; i++) {

            assert res[i].equals(ans[i]);

        }

    }
}
