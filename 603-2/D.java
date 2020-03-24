import java.util.Scanner;
//import java.util.Arrays;

public class D {
    public static int[] l = new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    public static boolean[] unique = new boolean[] {false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        for (int i = 0; i < n; ++i) {
            char[] password = in.nextLine().toCharArray();
            int cur = password[0] - 97;
            union(cur, cur);

            for (int j = 1; j < password.length; ++j) {
                int num = password[j] - 97;
                union(cur, num);
                cur = num;
            }
        }

        int count = 0;
        for (int p = 0; p < 26; ++p) {
            if (l[p] != -1 && !unique[find(p)]) {
                unique[find(p)] = true;
                ++count;
            }
        }
        
        //System.out.println(Arrays.toString(l));
        //System.out.println(Arrays.toString(unique));
        System.out.println(count);

        in.close();
    }

    public static void union(int a, int b) {
        if (l[a] == -1) {
            l[a] = a;
        }
        l[b] = l[a];
    }

    public static int find(int a) {
        if (l[a] == a) {
            return a;
        }
        l[a] = find(l[a]);
        return l[a];
    }
}