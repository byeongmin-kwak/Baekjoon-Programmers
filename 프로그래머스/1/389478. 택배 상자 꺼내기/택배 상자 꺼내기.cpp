#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    // 현재 층
    int currentFloor = (num-1) / w + 1;
    // 최고 층
    int height = (n-1) / w + 1;
    
    // 일단 최고 층 기준으로 계산
    answer = height - currentFloor + 1;
    
    int currentPosition = num % w;
    if (currentPosition == 0) currentPosition = w;
    int maxPosition = n % w;
    if (maxPosition == 0) maxPosition = w;
    
    int currentDirection;
    if (currentFloor % 2 == 0) {
        currentDirection = 0;

    } else {
        currentDirection =  1;
    }
    
    int maxDirection;
    if (height % 2 == 0) {
        maxDirection = 0;
    } else {
        maxDirection = 1;
    }
    
    if (currentDirection == maxDirection) {
        if (currentPosition > maxPosition) answer--;
    } else {
        if (currentPosition + maxPosition < w+1) answer--;
    }
    
    return answer;
}