#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int startPointX;
    int startPointY;
    
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == 'S') {
                startPointX = j;
                startPointY = i;
            }
        }
    }
    
    int currentIndexX = startPointX;
    int currentIndexY = startPointY;
    
    
    
    for (int i = 0 ; i < routes.size(); i++) {
        bool check = true;
        
        if (routes[i][0] == 'N') {
            if (currentIndexY - (routes[i][2]-'0') < 0) {
                continue;
            }
            else {
                for (int index = 1; index <= routes[i][2]-'0'; index++) {
                    if (park[currentIndexY-index][currentIndexX] == 'X') {
                        check = false;
                        continue;
                    }
                }
            }
            if (check)
            currentIndexY -= routes[i][2]-'0';
            
            cout << currentIndexY << ' ' << currentIndexX << 'N' << endl;
        }
        else if (routes[i][0] == 'E') {
            if (currentIndexX + routes[i][2]-'0' >= park[0].size()) {
                continue;
            }
            else {
                for (int index = 1; index <= routes[i][2]-'0'; index++) {
                    if (park[currentIndexY][currentIndexX+index] == 'X') {
                        check = false;
                        continue;
                    }
                }
            }
            if (check)
            currentIndexX +=  routes[i][2]-'0';
            
            cout << currentIndexY << ' ' << currentIndexX << 'E' << endl;

        }
        else if (routes[i][0] == 'S') {
            if (currentIndexY + routes[i][2]-'0' >= park.size()) {
                continue;
            }
            else {
                for (int index = 1; index <= routes[i][2]-'0'; index++) {
                    if (park[currentIndexY+index][currentIndexX] == 'X') {
                        check = false;
                        continue;
                    }
                }
            }
            if (check)
            currentIndexY += routes[i][2]-'0';
            
            cout << currentIndexY << ' ' << currentIndexX << 'S' << endl;

        }
        else if (routes[i][0] == 'W') {
            if (currentIndexX - (routes[i][2]-'0') < 0) {
                continue;
            }
            else {
                for (int index = 1; index <= routes[i][2]-'0'; index++) {
                    if (park[currentIndexY][currentIndexX-index] == 'X') {
                        check = false;
                        continue;
                    }
                }
            }
            if (check)
            currentIndexX -= routes[i][2]-'0';
            
            cout << currentIndexY << ' ' << currentIndexX << 'W'<< endl;

        }
    }
    
    answer.push_back(currentIndexY);
    answer.push_back(currentIndexX);
    
    return answer;
}
