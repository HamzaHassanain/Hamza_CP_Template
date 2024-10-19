
public class TC3 {

    public static void main(String[] args) {
        long x = 2;
        long y = 2;
        long a = 4;
        long b = 4;

        long c = 4;
        long[] asIn = { 11, 12, 13, 14 };
        long[] bsIn = { 21, 22, 23, 24 };
        long[] csIn = { 1, 2, 3, 4 };
        long res = 74;

        Solution sol = new Solution();
        long ans = sol.solve(x, y, a, b, c, asIn, bsIn, csIn);

        assert (ans == res);

    }
}
