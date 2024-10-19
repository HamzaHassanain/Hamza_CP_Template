
public class Solution {

    public static void dfs(String[] grid, int w, int i, int j) {

        if (!(i >= 0 && i < grid.length && j >= 0 && j < grid.length)) {
            return;
        }
        if (grid[i].charAt(j) == '#') {
            return;
        }
        if (grid[i].charAt(j) == 'V') {
            return;
        }

        grid[i] = grid[i].substring(0, j) + 'V' + grid[i].substring(j + 1);

        for (int d = -w; d <= w; d++) {
            for (int k = -w; k <= w; k++) {
                dfs(grid, w, i + d, j + k);
            }
        }
    }

    String[] solve(long n, long w, String[] grid) {

        for (int i = 0; i < n; i++) {
            if (grid[i].contains("P")) {
                for (int j = 0; j < n; j++) {
                    if (grid[i].charAt(j) == 'P') {
                        dfs(grid, (int) w, i, j);
                        break;
                    }
                }
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder(grid[i]);
            for (int j = 0; j < n; j++) {
                if (grid[i].charAt(j) == 'V') {
                    sb.setCharAt(j, 'P');
                }
            }
            grid[i] = sb.toString();
        }

        return grid;
    }
}
