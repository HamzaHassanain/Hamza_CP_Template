import java.util.*;

public class Solution {

    public long solve(long x, long y, long a, long b, long c, long asIn[], long bsIn[], long csIn[]) {
        ArrayList<Long> as = new ArrayList<>();
        ArrayList<Long> bs = new ArrayList<>();
        ArrayList<Long> cs = new ArrayList<>();

        for (int i = 0; i < a; i++) {
            as.add(asIn[i]);
        }
        for (int i = 0; i < b; i++) {
            bs.add(bsIn[i]);
        }
        for (int i = 0; i < c; i++) {
            cs.add(csIn[i]);
        }

        Collections.sort(as, Collections.reverseOrder());
        Collections.sort(bs, Collections.reverseOrder());
        Collections.sort(cs, Collections.reverseOrder());

        while (as.size() > x) {
            as.remove(as.size() - 1);
        }
        while (bs.size() > y) {
            bs.remove(bs.size() - 1);
        }

        TreeMap<Long, Long> a_mst = new TreeMap<>();
        TreeMap<Long, Long> b_mst = new TreeMap<>();

        for (long i : as) {
            if (a_mst.containsKey(i)) {
                a_mst.put(i, a_mst.get(i) + 1);
            } else {
                a_mst.put(i, 1L);
            }
        }

        for (long i : bs) {
            if (b_mst.containsKey(i)) {
                b_mst.put(i, b_mst.get(i) + 1);
            } else {
                b_mst.put(i, 1L);
            }
        }

        for (int i = 0; i < cs.size(); i++) {
            long a_frnt = a_mst.firstKey();
            long b_frnt = b_mst.firstKey();
            if (cs.get(i) >= Math.min(a_frnt, b_frnt)) {
                if (a_frnt < b_frnt) {
                    a_mst.put(a_frnt, a_mst.get(a_frnt) - 1);
                    if (a_mst.get(a_frnt) == 0) {
                        a_mst.remove(a_frnt);
                    }
                    a_mst.put(cs.get(i), a_mst.getOrDefault(cs.get(i), 0L) + 1);
                } else {
                    b_mst.put(b_frnt, b_mst.get(b_frnt) - 1);
                    if (b_mst.get(b_frnt) == 0) {
                        b_mst.remove(b_frnt);
                    }
                    b_mst.put(cs.get(i), b_mst.getOrDefault(cs.get(i), 0L) + 1);
                }
            }
        }

        long ans = 0;

        for (Map.Entry<Long, Long> entry : a_mst.entrySet()) {
            ans += entry.getKey() * entry.getValue();
        }

        for (Map.Entry<Long, Long> entry : b_mst.entrySet()) {
            ans += entry.getKey() * entry.getValue();
        }

        return ans;

    }
}
