class Solution {
    public long solution(int price, int money, int count) {
        long answer = -1;
        
        long tmp = 0;
        for (int i = 1; i <= count; i++) {
            tmp += price * i;
        }
        
        if (tmp > money) {
            answer = tmp - money;
        }
        else {
            answer = 0;
        }

        return answer;
    }
}