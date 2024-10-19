
public class TC3 {
    public static void main(String[] args) {

        long n = 3, w = 1;
        String[] grid = new String[] {
                "...",
                ".P.",
                "..."
        };

        String[] ans = new String[] {
                "PPP",
                "PPP",
                "PPP"
        };

        Solution s = new Solution();
        String[] res = s.solve(n, w, grid);

        assert res.length == ans.length;

        for (int i = 0; i < res.length; i++) {

            assert res[i].equals(ans[i]);

        }

    }
}
