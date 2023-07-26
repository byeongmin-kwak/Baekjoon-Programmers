import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;

class Solution {
    
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    boolean visited[][];
    
    public int solution(String[] maps) {
        int answer1 = -1;
        int answer2 = -1;
        int answer = -1;
        
        int startX = 0;
        int startY = 0;
        
        int leverX = 0;
        int leverY = 0;
        
        visited = new boolean[maps.length][maps[0].length()];
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) == 'S') {
                    startX = j;
                    startY = i;
                }
            }
        }
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) == 'L') {
                    leverX = j;
                    leverY = i;
                }
            }
        }
        
        Queue<int[]> que = new LinkedList<>();
        
        que.add(new int[]{startX, startY, 0});
        visited[startY][startX] = true;
        
        while(!que.isEmpty()) {
            int x = que.peek()[0];
            int y = que.peek()[1];
            int cnt = que.peek()[2];
            que.remove();            
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= maps[0].length() || ny < 0 || ny >= maps.length) {
                    continue;
                }
                if (maps[ny].charAt(nx) == 'X' || visited[ny][nx]) {
                    continue;
                }
                if (maps[ny].charAt(nx) == 'L') {
                    answer1 = cnt+1;
                    que.clear();
                    break;
                }
                que.add(new int[] {nx, ny, cnt+1});
                visited[ny][nx] = true;
            }
        }
        if (answer1 == -1) {
            return -1;
        }
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                visited[i][j] = false;
            }
        }
        
        visited[leverY][leverX] = true;
        que.add(new int[] {leverX, leverY, 0});
        
        while(!que.isEmpty()) {
            int x = que.peek()[0];
            int y = que.peek()[1];
            int cnt = que.peek()[2];
            que.remove();            
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= maps[0].length() || ny < 0 || ny >= maps.length) {
                    continue;
                }
                if (maps[ny].charAt(nx) == 'X' || visited[ny][nx]) {
                    continue;
                }
                if (maps[ny].charAt(nx) == 'E') {
                    answer2 = cnt+1;
                    que.clear();
                    break;
                }
                que.add(new int[] {nx, ny, cnt+1});
                visited[ny][nx] = true;
            }
        }
        if (answer2 == -1) {
            return -1;
        }
        
        answer = answer1 + answer2;
        return answer;
    }
}