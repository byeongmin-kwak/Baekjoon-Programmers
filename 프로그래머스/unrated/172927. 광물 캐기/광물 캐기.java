import java.util.Arrays;

class Solution {
    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        
        int idx = (int)Math.ceil((double)minerals.length/5);
        
        int[][] arr = new int[idx][3];
        
        int pickSum = 0;
        for (int i : picks) pickSum += i*5;
        
        for (int i = 0; i < idx; i++) {
            for (int j = i*5; j < Math.min((i+1)*5, minerals.length); j++) {
                if (minerals[j].equals("diamond")) {
                    arr[i][0]++;
                }
                else if (minerals[j].equals("iron")) {
                    arr[i][1]++;
                }
                else {
                    arr[i][2]++;
                }
            }
            
            pickSum -= 5;
            if (pickSum == 0) {
                Arrays.sort(arr, (o1, o2) -> {
                    if (o1[0] == o2[0]) {
                       return o2[1] - o1[1];
                    } 
                    else {
                        return o2[0] - o1[0];
                    }
                });
                break;
            }
        }
        
        if (pickSum != 0) {
            Arrays.sort(arr, (o1, o2) -> {
                if (o1[0] == o2[0]) {
                    return o2[1] - o1[1];
                }
                else {
                    return o2[0] - o1[0];
                }
            });
        }
        
        for (int i = 0; i < arr.length; i++) {
            if (picks[0] > 0) {
                answer += arr[i][0] + arr[i][1] + arr[i][2];
                picks[0]--;
            }
            else if (picks[1] > 0) {
                answer += arr[i][0]*5 + arr[i][1] + arr[i][2];
                picks[1]--;
            }
            else if (picks[2] > 0) {
                answer += arr[i][0]*25 + arr[i][1]*5 + arr[i][2];
                picks[2]--;
            }
            else {
                
            }
        }
        
        return answer;
    }
}