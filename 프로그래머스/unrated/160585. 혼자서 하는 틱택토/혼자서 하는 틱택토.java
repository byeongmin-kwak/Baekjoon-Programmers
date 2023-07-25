class Solution {
    public int solution(String[] board) {
        int answer = 1;
        
        int cntO = 0;
        int cntX = 0;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == 'O') {
                    cntO++;
                }        
                else if (board[i].charAt(j) == 'X') {
                    cntX++;
                }
            }
        }
        
        int threeO = 0;
        int threeX = 0;
        boolean checkO = true;
        boolean checkX = true;
        
        //가로 확인
        for (int i = 0; i < 3; i++) {
            checkO = true;
            checkX = true;
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == 'O' || board[i].charAt(j) == '.') {
                    checkX = false;
                }
                if (board[i].charAt(j) == 'X' || board[i].charAt(j) == '.') {
                    checkO = false;
                }
            }
            if (checkO) {
                threeO++;
            }
            if (checkX) {
                threeX++;
            }
        }
        
        //세로 확인
        for (int i = 0; i < 3; i++) {
            checkO = true;
            checkX = true;
            for (int j = 0; j < 3; j++) {
                if (board[j].charAt(i) == 'O' || board[j].charAt(i) == '.') {
                    checkX = false;
                }
                if (board[j].charAt(i) == 'X' || board[j].charAt(i) == '.') {
                    checkO = false;
                }
            }
            if (checkO) {
                threeO++;   
            }
            if (checkX) {
                threeX++;
            }
        }
        
        //대각선 확인
        checkO = true;
        checkX = true;
        for (int i = 0; i < 3; i++) {
            if (board[i].charAt(i) == 'O' || board[i].charAt(i) == '.') {
                checkX = false;
            }
            if (board[i].charAt(i) == 'X' || board[i].charAt(i) == '.') {
                checkO = false;
            }
        }
        if (checkO) {
            threeO++;
        }
        if (checkX) {
            threeX++;
        }
        
        checkO = true;
        checkX = true;
        for (int i = 0; i < 3; i++) {
            if (board[i].charAt(2-i) == 'O' || board[i].charAt(2-i) == '.') {
                checkX = false;
            }
            if (board[i].charAt(2-i) == 'X' || board[i].charAt(2-i) == '.') {
                checkO = false;
            }
        }
        if (checkO) {
            threeO++;
        }
        if (checkX) {
            threeX++;
        }
        
        // System.out.print(threeO);
        // System.out.print(' ');
        // System.out.print(threeX);
        // System.out.println();
        // System.out.print(cntO);
        // System.out.print(' ');
        // System.out.print(cntX);
        // System.out.println();
        
        if (cntO < cntX || cntO > cntX+1) {
            return 0;
        }
        if (threeO > 0 && threeX > 0) {
            return 0;
        }
        if (threeO > 0) {
            if (cntO == cntX) {
                return 0;
            }
        }
        if (threeX > 0) {
            if (cntO > cntX) {
                return 0;
            }
        }
        
        
        return answer;
    }
}