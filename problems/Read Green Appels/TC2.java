
public class TC2 {

    public static void main(String[] args) {
        long x = 2;
        long y = 2;
        long a = 2;
        long b = 2;

        long c = 2;
        long[] asIn = { 8, 6 };
        long[] bsIn = { 9, 1 };
        long[] csIn = { 2, 1 };
        long res = 25;

        Solution sol = new Solution();
        long ans = sol.solve(x, y, a, b, c, asIn, bsIn, csIn);

        assert (ans == res);

    }
}
