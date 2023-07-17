import java.util.Arrays;
import java.util.ArrayList;

class Solution {
    public ArrayList solution(int[] answers) {
        
        int a = 0;
        int b = 0;
        int c = 0;
        
        //a
        for (int i = 0; i < answers.length; i++) {
            if ((i+1)%5 == 0) {
                if (answers[i] == 5) {
                    a++;
                }
            }
            else {
                if (answers[i] == (i+1)%5) {
                    a++;
                }
            }
        }
        
        //b
        int tmp = 0;
        for (int i = 0; i < answers.length; i++) {
            if ((i+1) % 2 != 0) {
                if (answers[i] == 2) {
                    b++;
                }
            }
            else {
                tmp++;
                if (tmp == 2) {
                    tmp = 3;
                }
                tmp = tmp % 5;
                if (tmp == 0) {
                    tmp = 5;
                }
                if (answers[i] == tmp) {
                    b++;
                }
            }
        }
        
        //c
        int[] arr = {3,3,1,1,2,2,4,4,5,5};
        
        for (int i = 0; i < answers.length; i++) {
            tmp = i%10;
            if (answers[i] == arr[tmp]) {
                c++;
            }
        }
        
        
        ArrayList<Integer> answer = new ArrayList<>();
        
        int max = Math.max(a, Math.max(b, c));
        
        if (max == a) {
            answer.add(1);
        }
        if (max == b) {
            answer.add(2);
        }
        if (max == c) {
            answer.add(3);
        }
        
        return answer;
    }
}