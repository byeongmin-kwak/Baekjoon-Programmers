class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        String s1 = Integer.toString(a)+Integer.toString(b);
        String s2 = Integer.toString(b)+Integer.toString(a);

        if (Integer.parseInt(s1) >= Integer.parseInt(s2)) {
            answer = Integer.parseInt(s1);
        }
        else {
            answer = Integer.parseInt(s2);
        }
        
        return answer;
    }
}