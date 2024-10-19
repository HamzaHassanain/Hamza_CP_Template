
public class TC4 {

    public static void main(String[] args) {

        long x = 1;
        long y = 1;
        long a = 1;
        long b = 1;
        long c = 1;
        long[] asIn = { 427448895 };
        long[] bsIn = { 593740822 };
        long[] csIn = { 438449517 };
        long res = 1032190339;

        Solution sol = new Solution();
        long ans = sol.solve(x, y, a, b, c, asIn, bsIn, csIn);

        assert (ans == res);

    }
}
