import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int solution(String[][] book_time) {
        int answer = 1;
        
        Arrays.sort(book_time, (o1, o2) -> {
           return o1[0].compareTo(o2[0]); 
        });
        
        PriorityQueue<String> pq = new PriorityQueue<>();
        
        pq.add(book_time[0][1]);
        
        for (int i = 1; i < book_time.length; i++) {
            String[] tmp1 = pq.peek().split(":");
            int a = Integer.parseInt(tmp1[0])*60 + Integer.parseInt(tmp1[1]);
            
            String[] tmp2 = book_time[i][0].split(":");
            int b = Integer.parseInt(tmp2[0])*60 + Integer.parseInt(tmp2[1]);
            
            if (a+10 <= b) {
                pq.remove();
                pq.add(book_time[i][1]);
            }
            else {
                pq.add(book_time[i][1]);
            }
            
            if (answer < pq.size()) {
                answer = pq.size();
            }
        }
        
        return answer;
    }
}