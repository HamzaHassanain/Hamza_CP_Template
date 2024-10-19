public class Solution {

    private static class Complex {
        private int x;
        private int y;

        public Complex(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Complex add(Complex other) {
            return new Complex(this.x + other.x, this.y + other.y);
        }

        public int real() {
            return x;
        }

        public int img() {
            return y;
        }
    }

    private Complex StringToComplex(String s) {

        int real = 0, img = 0;
        boolean neg = false;
        neg = s.charAt(0) == '-';
        String part = "";
        int i = neg ? 1 : 0;
        for (; i < s.length(); i++) {
            if (s.charAt(i) == '-' || s.charAt(i) == '+') {
                real = (neg ? -1 : 1) * Integer.parseInt(part);
                neg = (s.charAt(i) == '-');
                part = "";
            } else if (s.charAt(i) == 'i') {
                if (part.length() == 0)
                    part = "1";
                img = (neg ? -1 : 1) * Integer.parseInt(part);
                part = "";
                break;
            } else {
                part += s.charAt(i);
            }
        }
        if (part.length() > 0)
            real = (neg ? -1 : 1) * Integer.parseInt(part);

        return new Complex(real, img);

    }

    public String ComplexToString(Complex c) {
        StringBuilder sb = new StringBuilder();
        if (c.real() != 0)
            sb.append(c.real());
        if (c.img() != 0) {
            if (c.img() > 0 && c.real() != 0)
                sb.append("+");
            if (c.img() == -1)
                sb.append("-i");
            else if (c.img() == 1)
                sb.append("i");
            else
                sb.append(c.img()).append("i");
        }
        if (c.real() == 0 && c.img() == 0)
            sb.append(0);
        return sb.toString();
    }

    public String solve(String x, String y) {
        Complex a = StringToComplex(x);
        Complex b = StringToComplex(y);
        Complex c = a.add(b);
        return ComplexToString(c);
    }

}