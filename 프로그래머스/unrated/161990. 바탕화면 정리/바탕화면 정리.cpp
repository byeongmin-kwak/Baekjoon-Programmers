#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
        
    int minX = 51;
    int minY = 51;
    int maxX = 0;
    int maxY = 0;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                if (i < minX) {
                    minX = i;
                }
                if (i+1 > maxX) {
                    maxX = i + 1;                    
                }
                if (j < minY) {
                    minY = j;
                }
                if (j+1 > maxY) {
                    maxY = j + 1;
                }
            }
        }
    }
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX);
    answer.push_back(maxY);
    
    return answer;
}