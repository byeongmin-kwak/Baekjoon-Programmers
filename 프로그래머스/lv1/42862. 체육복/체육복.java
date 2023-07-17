import java.util.Arrays;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        answer = n - lost.length;
        Arrays.sort(reserve);

        
        int arr[] = new int[n+2];
        
        for (int i = 0; i < n+2; i++) {
            arr[i] = 0;
        }
        for (int i : lost) {
            arr[i] = -1;
        }
        for (int i = 0; i < reserve.length; i++) {
            if (arr[reserve[i]] == -1) {
                arr[reserve[i]] = 0;
                reserve[i] = 0;
                answer++;
            }
        }
        
        for (int i : reserve) {
            if (answer >= n) {
                return answer;
            }
            if (i == 0) {
                continue;
            }
            if (arr[i-1] == -1) {
                answer++;
                continue;
            }
            else if (arr[i+1] == -1) {
                answer++;
                arr[i+1] = 0;
            }
        }
        
        return answer;
    }
}