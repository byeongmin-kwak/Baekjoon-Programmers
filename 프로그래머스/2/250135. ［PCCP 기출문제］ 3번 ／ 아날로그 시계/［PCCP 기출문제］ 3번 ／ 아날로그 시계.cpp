#include <string>
#include <vector>
#include <iostream>
#include <cmath>  

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    int startTime = h1 * 3600 + m1 * 60 + s1;
    int endTime = h2 * 3600 + m2 * 60 + s2;

    if (startTime == 0 * 3600 || startTime == 12 * 3600) {
        answer += 1;
    }

    while (startTime < endTime) {
   
        double hCurAngle = fmod(startTime / 120.0, 360);
        double mCurAngle = fmod(startTime / 10.0, 360);
        double sCurAngle = fmod(startTime * 6.0, 360);

        double hNextAngle = fmod(((startTime + 1) / 120.0),360) == 0 ? 360 : fmod((startTime + 1) / 120.0, 360);
        double mNextAngle = fmod(((startTime + 1) / 10.0),360) == 0 ? 360 : fmod((startTime + 1) / 10.0,360);
        double sNextAngle = fmod(((startTime + 1) * 6.0),360) == 0 ? 360 : fmod((startTime + 1) * 6.0,360);

        if (sCurAngle < hCurAngle && sNextAngle >= hNextAngle) {
            answer += 1;
        }
        if (sCurAngle < mCurAngle && sNextAngle >= mNextAngle) {
            answer += 1;
        }
        if (sNextAngle == hNextAngle && hNextAngle == mNextAngle) {
            answer -= 1;
        }

        startTime += 1;
    }

    return answer;
}