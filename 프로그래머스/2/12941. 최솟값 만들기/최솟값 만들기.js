function solution(A,B){
    let answer = 0;

    A.sort((a, b) => a - b);
    B.sort((a, b) => a - b);
    
    for (let i = 0; i < A.length; i++) {
        answer += A[i] * B[B.length-i-1];
    }
    
    
    return answer;
}