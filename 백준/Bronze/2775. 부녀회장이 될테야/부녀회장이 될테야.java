import java.util.Scanner;
public class Main {
    public static void main(String[] args) {

        int[][] arr = new int[15][15];

        for (int i = 0; i <= 14; i++) {
            arr[0][i] = i;
        }

        for (int i = 1; i <= 14; i++) {
            for (int j = 1; j <= 14; j++) {
                for (int k = 1; k <= j; k++) {
                    arr[i][j] += arr[i-1][k];
                }
            }
        }

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int a = in.nextInt();
            int b = in.nextInt();

            System.out.println(arr[a][b]);
        }
//
//        for (int i = 0; i <= 14; i++) {
//            for (int j = 1; j <= 14; j++) {
//                System.out.print(arr[i][j] + " ");
//            }
//            System.out.println();
//        }

    }
}

