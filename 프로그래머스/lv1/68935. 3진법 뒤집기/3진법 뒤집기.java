class Solution {
    public int solution(int n) {
        int answer = 0;
        
        String s = "";
        
        while (n / 3 != 0) {
            s += (n % 3);
            n /= 3;
        }
        s += n % 3;
        
        for (int i = s.length()-1; i >= 0; i--) {
            answer += (s.charAt(i)-'0') * Math.pow(3, s.length()-1-i);
        }
                
        return answer;
    }
}