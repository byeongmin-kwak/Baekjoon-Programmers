function solution(arr) {
    // 최대공약수
    const gcd = (a, b) => (b === 0 ? a : gcd(b, a % b));
    // 최소공배수
    const lcm = (a, b) => (a * b) / gcd(a, b);

    return arr.reduce((acc, cur) => lcm(acc, cur));
}
