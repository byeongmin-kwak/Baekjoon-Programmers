import java.util.ArrayList;

class Solution {
    public ArrayList solution(int[] numbers) {
        ArrayList<Integer> tmp = new ArrayList<>();
        ArrayList<Integer> answer = new ArrayList<>();
        
        
        tmp.add(-1);
        for (int i = numbers.length-2; i >= 0; i--) {
            if (numbers[i] < numbers[i+1]) {
                tmp.add(numbers[i+1]);
            }
            else {
                for (int j = tmp.size()-1; j >= 0; j--) {
                    if (numbers[i] < tmp.get(j)) {
                        tmp.add(tmp.get(j));
                        break;
                    }
                    else if (tmp.get(j) == -1) {
                        tmp.add(-1);
                        break;
                    }
                    
                }
            }
        }
        
        for (int i = tmp.size()-1; i >= 0; i--) {
            answer.add(tmp.get(i));
        }
        
        
        return answer;
    }
}