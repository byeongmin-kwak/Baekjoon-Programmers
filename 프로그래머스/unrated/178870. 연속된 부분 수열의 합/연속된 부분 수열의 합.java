import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0, 1000001};
        
        int[] arr = new int[sequence.length];
        arr[0] = sequence[0];
        
        Queue<Integer> que = new LinkedList<>();
        
        que.add(0);
        if (sequence[0] == k) {
            answer[0] = 0;
            answer[1] = 0;
            return answer;
        }
        
        for (int i = 1; i < sequence.length; i++) {
            if (sequence[i] == k) {
                answer[0] = i;
                answer[1] = i;
                break;
            }
            if (arr[i-1] + sequence[i] <  k) {
                arr[i] = arr[i-1] + sequence[i];
            }
            else if (arr[i-1] + sequence[i] == k) {
                arr[i] = k;
                if (answer[1] - answer[0] > i - que.peek()) {
                    answer[1] = i;
                    answer[0] = que.peek();
                }
            }
            else {
                if (sequence[i] > k) {
                    break;
                }
                int tmp = arr[i-1] + sequence[i];
                while (tmp > k) {
                    que.add(que.peek()+1);
                    tmp -= sequence[que.peek()];
                    que.remove();
                }
                if (tmp == k) {
                    if (answer[1] - answer[0] > i - que.peek()) {
                        answer[1] = i;
                        answer[0] = que.peek();
                        arr[i] = k;
                    }
                }
                else {
                    arr[i] = tmp;
                }
            }
        }
        return answer;
    }
}