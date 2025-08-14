function solution(points, routes) {
    let answer = 0;
    
    // 현재 로봇들의 위치
    let current = [];
    for (let i = 0; i < routes.length; i++) {
        current.push([...points[routes[i][0]-1]]);
    }
    
    // route를 다 거쳤는지 확인하는 배열
    let flag = [];
    for (let i = 0; i < routes.length; i++) {
        flag[i] = [];
        for (let j = 0; j < routes[i].length; j++) {
            flag[i][j] = false;
        }
    }
    
    while (true) {
        // 현재 위치에서 충돌이 있는지 체크
// 현재 위치에서 충돌 체크
let seen = new Map();
for (let i = 0; i < current.length; i++) {
    if (flag[i][flag[i].length - 1]) continue; // 도착한 로봇 무시
    let key = current[i][0] + ',' + current[i][1];
    seen.set(key, (seen.get(key) || 0) + 1);
}
for (let [key, count] of seen) {
    if (count >= 2) answer++; // 같은 좌표에 2대 이상이면 1번만 증가
}

        
        // 다 이동했는지 체크
        let finish = true;
        for (let i = 0; i < flag.length; i++) {
            if (!flag[i][flag[i].length-1]) {
                finish = false;
                break;
            };
        }
        if (finish) break;
        
        // 루트를 확인하며 이동
        for (let i = 0; i < flag.length; i++) {
            for (let j = 0; j < flag[i].length; j++) {
                if (!flag[i][j]) {
                    let target = points[routes[i][j]-1];
                    if (current[i][0] < target[0]) current[i][0]++;
                    else if (current[i][0] > target[0]) current[i][0]--;
                    else if (current[i][1] < target[1]) current[i][1]++;
                    else if (current[i][1] > target[1]) current[i][1]--;
                    else {
                        flag[i][j] = true;
                        continue;
                    }
                    break;
                }
            }
        }
    }
    
    return answer;
}