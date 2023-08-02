import java.util.Queue;
import java.util.LinkedList;
import java.util.Collections;

class Solution {
    
    boolean[][] visited;
    Queue<int[]> que = new LinkedList<>();
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    
    public LinkedList solution(String[] maps) {
        
        visited = new boolean[maps.length][maps[0].length()];
        LinkedList<Integer> answer = new LinkedList<>();
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (!visited[i][j] && maps[i].charAt(j) != 'X') {
                    que.add(new int[]{maps[i].charAt(j)-'0', j, i});
                    visited[i][j] = true;
                    int sum = 0;
                    while(!que.isEmpty()) {
                        int num = que.peek()[0];
                        int x = que.peek()[1];
                        int y = que.peek()[2];
                        que.remove();
            
                        sum += num;
            
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                
                            if (nx >= 0 && nx < maps[0].length() && ny >= 0 && ny < maps.length) {
                                if (maps[ny].charAt(nx) != 'X' && !visited[ny][nx]) {
                                    que.add(new int[]{maps[ny].charAt(nx)-'0', nx, ny});
                                    visited[ny][nx] = true;
                                }
                            }
                        }
                    }
                    answer.add(sum);
                }
            }
        }
        if (answer.size() == 0) {
            answer.add(-1);
        }
        
        Collections.sort(answer);

        
        return answer;
    }
}