class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        String s = Integer.toString(a)+Integer.toString(b);
        int x = Integer.parseInt(s);
        int y = 2 * a * b;
        
        if (x >= y) {
            answer = x;
        }
        else {
            answer = y;
        }
        
        
        return answer;
    }
}