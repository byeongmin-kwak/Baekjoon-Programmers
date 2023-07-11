class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        
        for (int i = left; i <= right; i++) {
            int cnt = 0;
            if (i == 1) {
                cnt = 1;
            }
            else {
                for (int j = 1; j <= i * i; j++) {
                    if (i % j == 0) {
                        cnt += 2;
                        if (j * j == i) {
                            cnt--;
                        }
                    }
                }
            }
            if (cnt % 2 == 0) {
                answer += i;
            }
            else {
                answer -= i;
            }
        }
        
        return answer;
    }
}