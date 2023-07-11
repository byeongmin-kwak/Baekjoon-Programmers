class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
        int cnt = 0;
        int zero = 0;
        for (int i = 0; i < 6; i++) {
            if (lottos[i] == 0) {
                zero++;
                continue;
            }
            for (int j = 0; j < 6; j++) {
                if (lottos[i] == win_nums[j]) {
                    cnt++;
                    break;
                }
            }
        }
        int[] answer = {Math.min(7-(cnt+zero), 6), Math.min(7-cnt,6)};
        
        return answer;
    }
}