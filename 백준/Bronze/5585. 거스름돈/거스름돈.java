import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Integer input = sc.nextInt();

        int change = 1000 - input;
        int cnt = 0;

        if (change >= 500) {
            cnt += change / 500;
            change %= 500;
        }
        if (change >= 100) {
            cnt += change / 100;
            change %= 100;
        }
        if (change >= 50) {
            cnt += change / 50;
            change %= 50;
        }
        if (change >= 10) {
            cnt += change / 10;
            change %= 10;
        }
        if (change >= 5) {
            cnt += change / 5;
            change %= 5;
        }
        if (change >= 1) {
            cnt += change / 1;
        }

        System.out.println(cnt);
    }
}