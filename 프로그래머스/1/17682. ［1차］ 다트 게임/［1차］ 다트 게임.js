function solution(dartResult) {
  let darts = dartResult.split(""); // 배열로 변환
  let scores = []; // 각 기회마다 얻은 점수 배열
  let score = 0; // 각 기회마다 얻은 점수

  for (let i = 0; i < darts.length; i++) {
    // 숫자 구하기
    if (!isNaN(darts[i])) {
      // 10인 경우
      if (darts[i] === "1" && darts[i + 1] === "0") {
        score = 10;
        i++; // 다음에 오는 0은 건너 뛰어야 함
      } else score = darts[i];
    }

    // 점수 구하기
    else if (darts[i] === "S") {
      scores.push(Math.pow(score, 1));
    } else if (darts[i] === "D") {
      scores.push(Math.pow(score, 2));
    } else if (darts[i] === "T") {
      scores.push(Math.pow(score, 3));
    }

    // 옵션 적용하기
    else if (darts[i] === "#") {
      scores[scores.length - 1] *= -1;
    } else if (darts[i] === "*") {
      scores[scores.length - 2] *= 2;
      scores[scores.length - 1] *= 2;
    }
  }

  // 점수 합계 구하기
  let sum = 0;
  for (let i = 0; i < scores.length; i++) {
    sum += scores[i];
  }

  return sum;
}
