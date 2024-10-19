
public class TC1 {

    public static void main(String[] args) {
        long x = 1;
        long y = 2;
        long a = 2;
        long b = 2;
        long c = 1;
        long[] asIn = { 2, 4 };
        long[] bsIn = { 5, 1 };
        long[] csIn = { 3 };
        long res = 12;

        Solution sol = new Solution();
        long ans = sol.solve(x, y, a, b, c, asIn, bsIn, csIn);

        assert (ans == res);

    }
}
