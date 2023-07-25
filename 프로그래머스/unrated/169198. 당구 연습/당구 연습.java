class Solution {
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        int[] answer = new int[balls.length];
        
        for (int i = 0; i < balls.length; i++) {
            int tx = balls[i][0];
            int ty = balls[i][1];
            
            int distance = Integer.MAX_VALUE;
            int tmp;
            
            //상
            if (!(startX == tx && startY < ty)) {
                tmp = (int) (Math.pow(startX-tx, 2) + Math.pow((n-startY)+(n-ty),2));
                distance = Math.min(distance, tmp);
            }
            
            //하
            if (!(startX == tx && startY > ty)) {
                tmp = (int) (Math.pow(startX-tx, 2) + Math.pow(startY+ty, 2));
                distance = Math.min(distance, tmp);
            }
            
            //좌
            if (!(startY == ty && startX > tx)) {
                tmp = (int) (Math.pow(startX+tx, 2) + Math.pow(startY-ty, 2));
                distance = Math.min(distance, tmp);
            }
            
            //우
            if (!(startY == ty && startX < tx)) {
                tmp = (int) (Math.pow((m-startX)+(m-tx), 2) + Math.pow(startY-ty, 2));
                distance = Math.min(distance, tmp);
            }
            
            answer[i] = distance;
        }
        
        
        return answer;
    }
}