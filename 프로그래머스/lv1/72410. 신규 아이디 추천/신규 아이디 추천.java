class Solution {
    public String solution(String new_id) {
        String answer = "";
        
        //1단게 대소문자
        new_id = new_id.toLowerCase();
        
        //2단계 특수문자
        String s = "";
        for (int i = 0; i < new_id.length(); i++) {
            if ((new_id.charAt(i) >= 'a' && new_id.charAt(i) <= 'z') || (new_id.charAt(i)-'0' >= 0 && new_id.charAt(i)-'0' <= 9) || new_id.charAt(i) == '-' || new_id.charAt(i) == '_' || new_id.charAt(i) == '.')
                s += new_id.charAt(i);
        }
        
        //3단계
        boolean tmp = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '.') {
                if (tmp) {
                    continue;
                }
                else {
                    tmp = true;
                    answer += s.charAt(i);
                }
            }
            else {
                answer += s.charAt(i);
                tmp = false;
            }
        }
        
        //4단계
        s = "";
        if (answer.charAt(0) == '.') {
            if (answer.charAt(answer.length()-1) == '.') {
                for (int i = 1; i < answer.length()-1; i++) {
                    s += answer.charAt(i);
                }
            }
            else {
                for (int i = 1; i < answer.length(); i++) {
                    s += answer.charAt(i);
                }
            }
        }
        else {
            if (answer.charAt(answer.length()-1) == '.') {
                for (int i = 0; i < answer.length()-1;i ++) {
                    s += answer.charAt(i);
                }
            }
            else {
                for (int i = 0; i < answer.length();i ++) {
                    s += answer.charAt(i);
                }
            }
        }
        
        //5단계
        if (s.length() == 0) {
            s += 'a';
        }
        
        //6단계
        answer = "";
        if (s.length() >= 16) {
            for (int i = 0; i < 15; i++) {
                answer += s.charAt(i);
            }
        }
        else {
            answer = s;
        }
        
        if (answer.charAt(answer.length()-1) == '.') {
            s = "";
            for (int i = 0; i < answer.length()-1; i++) {
                s += answer.charAt(i);
            }
            answer = s;
        }
        
        
        //7단계
        while (answer.length() <= 2) {
            answer += answer.charAt(answer.length()-1);
        }
                
        return answer;
    }
}