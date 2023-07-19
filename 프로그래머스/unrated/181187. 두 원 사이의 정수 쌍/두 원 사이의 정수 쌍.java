class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        for (int x = 1; x <= r2; x++) {
            long small = (long)Math.ceil(Math.sqrt(Math.pow(r1,2) - Math.pow(x,2)));
            long big = (long)Math.floor(Math.sqrt(Math.pow(r2,2) - Math.pow(x,2)));
            
            // System.out.println(small);
            // System.out.println(big);
            answer += big - small + 1;
    
        }
        
        answer = answer * 4;
        
        return answer;
    }
    
    
}