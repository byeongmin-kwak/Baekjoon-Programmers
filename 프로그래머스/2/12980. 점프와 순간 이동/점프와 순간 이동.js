function solution(n) {
    let ans = 1;
    
    while (n > 1) {
        if (n % 2 !== 0) {
            n--;
            ans++;
        }
        else {
            n /= 2;
        }
    }

    

    return ans;
}