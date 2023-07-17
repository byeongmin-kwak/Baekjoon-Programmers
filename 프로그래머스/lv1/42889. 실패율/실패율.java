import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public ArrayList solution(int N, int[] stages) {
        Arrays.sort(stages); 
        
        ArrayList<Integer> list = new ArrayList<>();
        
        for (int stage : stages) {
            list.add(stage);
        }
        
        double[][] arr = new double[N][2];
        
        for (int i = 1; i <= N; i++) {
            int count = Collections.frequency(list, i);
            double tmp = 0;
            for (int j = 0; j < list.size(); j++) {
                if (list.get(j) >= i) {
                    tmp = (double)count / (list.size()-j);
                    break;
                }
            }
            arr[i-1][0] = (double)i;
            arr[i-1][1] = tmp;
        }
        
        Arrays.sort(arr, new Comparator<double[]>() {
            public int compare(double[] o1, double[] o2) {
                return Double.compare(o2[1], o1[1]);
            }
        });
        
        ArrayList<Integer> answer = new ArrayList<>();
        
        for (int i = 0; i < arr.length; i++) {
            answer.add((int)arr[i][0]);
        }
    
        return answer;
    }
}