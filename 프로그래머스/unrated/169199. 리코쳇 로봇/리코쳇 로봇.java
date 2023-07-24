import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(String[] board) {
        int answer = 0;
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        boolean[][] visited = new boolean[board.length][board[0].length()];
        
        Queue<int[]> que = new LinkedList<>();
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i].charAt(j) == 'R') {
                    que.add(new int[]{i,j,0});
                    visited[i][j] = true;
                    break;
                }
            }
        }

        while (!que.isEmpty()) {
            int x = que.peek()[1];
            int y = que.peek()[0];
            int cnt = que.peek()[2];
            que.remove();
            
            for (int i = 0; i < 4; i++) {
                int nx = x;
                int ny = y;
                while (true) {
                    nx += dx[i];
                    ny += dy[i];
                    
                    if (nx < 0 || nx >= board[0].length() || ny < 0 || ny >= board.length || board[ny].charAt(nx) == 'D') {
                        nx -= dx[i];
                        ny -= dy[i];
                        break;
                    }
                }
                
                if (board[ny].charAt(nx) == 'G') {
                    answer = cnt + 1;
                    return answer;
                }
                
                if (!visited[ny][nx]) {
                    que.add(new int[]{ny, nx, cnt+1});
                    visited[ny][nx] = true;
                }
            }
            
        }
        
        return -1;
    }
}