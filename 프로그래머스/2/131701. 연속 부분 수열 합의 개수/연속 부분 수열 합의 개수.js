function solve(elements, size, set) {
    for (let i = 0; i < elements.length; i++) {
        sum = 0;
        for (let j = 0; j < size; j++) {
            sum += elements[(i+j)% elements.length];
        }
        set.add(sum);
    }
}

function solution(elements) {
    let answer = 0;
    let set = new Set();
    
    for (let i = 1; i <= elements.length; i++) {
        solve(elements, i, set);
    }
    
    answer = set.size;
    
    return answer;
}