import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.ArrayList;

class Solution {
    public ArrayList solution(String[][] plans) {
        ArrayList<String> answer = new ArrayList<>();
        
        Arrays.sort(plans, new Comparator<String[]>() {
	        public int compare(String[] o1, String[] o2) {
		        return o1[1].compareTo(o2[1]);
	        }
        });
        
        Stack<Integer> st = new Stack<>();
        
        int currentHour, hour;
        int currentMinute, minute;
        int time;
        
        currentHour = Integer.parseInt(plans[0][1].substring(0,2));
        currentMinute = Integer.parseInt(plans[0][1].substring(3,5));
        
        for (int i = 0; i < plans.length-1; i++) {
            time = Integer.parseInt(plans[i][2]);
            hour = Integer.parseInt(plans[i+1][1].substring(0,2));
            minute = Integer.parseInt(plans[i+1][1].substring(3,5));
            
            if (currentMinute + time >= 60) {
                currentHour += (currentMinute + time) / 60;
                currentMinute = (currentMinute+time) % 60;
            }
            else {
                currentMinute += time;
            }
            
            if (currentHour > hour) {
                st.add(i);
                while (currentHour > hour) {
                    currentHour--;
                    currentMinute += 60;
                }
                plans[i][2] = Integer.toString(currentMinute - minute);
                currentHour = hour;
                currentMinute = minute;
                continue;
            }
            else if (currentHour == hour) {
                if (currentMinute > minute) {
                    st.add(i);
                    plans[i][2] = Integer.toString(currentMinute - minute);
                    currentHour = hour;
                    currentMinute = minute;
                    continue;
                }
                else {
                    answer.add(plans[i][0]);
                    if (st.empty()) {
                        currentHour = hour;
                        currentMinute = minute;
                        continue;
                    }
                    while (!st.empty()) {
                        time = Integer.parseInt(plans[st.peek()][2]);
                        if (currentMinute + time >= 60) {
                            currentHour += (currentMinute + time) / 60;
                            currentMinute = (currentMinute+time) % 60;
                        }
                        else {
                            currentMinute += time;
                        
                        }
                        if (currentHour > hour) {
                            while (currentHour > hour) {
                                currentHour--;
                                currentMinute += 60;
                            }
                            plans[st.peek()][2] = Integer.toString(currentMinute - minute);
                            currentHour = hour;
                            currentMinute = minute;
                            break;
                        }
                        else if (currentHour == hour) {
                            if (currentMinute > minute) {
                                plans[st.peek()][2] = Integer.toString(currentMinute - minute); 
                                currentHour = hour;
                                currentMinute = minute;
                                break;
                            }
                            else {
                                answer.add(plans[st.peek()][0]);
                                st.pop();
                            }
                        }
                        else {
                            answer.add(plans[st.peek()][0]);
                            st.pop();
                        }
                    }
                    if (st.empty()) {
                        currentHour = hour;
                        currentMinute = minute;
                    }
                }
            }
            else {
                answer.add(plans[i][0]);
                if (st.empty()) {
                    currentHour = hour;
                    currentMinute = minute;
                    continue;
                }
                while (!st.empty()) {
                    time = Integer.parseInt(plans[st.peek()][2]);
                    if (currentMinute + time >= 60) {
                        currentHour += (currentMinute + time) / 60;
                        currentMinute = (currentMinute+time) % 60;
                    }
                    else {
                        currentMinute += time;
                    }
                    
                    if (currentHour > hour) {
                        while (currentHour > hour) {
                            currentHour--;
                            currentMinute += 60;
                        }
                        plans[st.peek()][2] = Integer.toString(currentMinute - minute);
                        currentHour = hour;
                        currentMinute = minute;
                        break;
                    }
                    else if (currentHour == hour) {
                        if (currentMinute > minute) {
                            plans[st.peek()][2] = Integer.toString(currentMinute - minute);
                            currentHour = hour;
                            currentMinute = minute;
                            break;
                        }
                        else {
                            answer.add(plans[st.peek()][0]);
                            st.pop();
                        }
                    }
                    else {
                        answer.add(plans[st.peek()][0]);
                        st.pop();
                    }
                }
                if (st.empty()) {
                    currentHour = hour;
                    currentMinute = minute;
                }
            }
        }
        
        answer.add(plans[plans.length-1][0]);
        
        while (!st.empty()) {
            answer.add(plans[st.peek()][0]);
            st.pop();
        }
        
        return answer;
    }
}