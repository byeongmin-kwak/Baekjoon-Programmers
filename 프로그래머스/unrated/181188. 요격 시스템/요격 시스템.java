import java.util.Comparator;
import java.util.Arrays;
import java.util.PriorityQueue;


class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        
        Arrays.sort(targets, new Comparator<int[]>() {
	        public int compare(int[] o1, int[] o2) {
		        return o1[0] - o2[0];
	        }
        });
        
        answer++;
        pq.add(targets[0][1]);
        
        for (int i = 1; i < targets.length; i++) {
            if (targets[i][0] >= pq.peek()) {
                answer++;
                pq.clear();
                pq.add(targets[i][1]);
            }
            else {
                pq.add(targets[i][1]);
            }
        }
        
        return answer;
    }
}