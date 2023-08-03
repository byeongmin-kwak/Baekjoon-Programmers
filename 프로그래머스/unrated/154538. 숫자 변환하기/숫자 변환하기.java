class Solution {
    public int solution(int x, int y, int n) {
        int answer = 0;
        int[] arr = new int[y+1];
        
        for (int i = 0; i <= y; i++) {
            arr[i] = Integer.MAX_VALUE;
        }
        
        arr[x] = 0;
        int a, b, c;
        for (int i = x+1; i <= y; i++) {
            a = b = c = Integer.MAX_VALUE;
            if (i % 2 == 0) {
                a = arr[i/2];
            }
            if (i % 3 == 0) {
                b = arr[i/3];
            }
            if (i - n >= x) {
                c = arr[i-n];
            }
            arr[i] = Math.min(a, Math.min(b, c));
            
            if (arr[i] != Integer.MAX_VALUE) {
                arr[i]++;
            }
        }
        
        
        if (arr[y] == Integer.MAX_VALUE) {
            answer = -1;
        }
        else {
            answer = arr[y];
        }
        
        
        
        return answer;
    }
}