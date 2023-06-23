#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayY = stoi(today.substr(0,4));
    int todayM = stoi(today.substr(5,2));
    int todayD = stoi(today.substr(8,2));
    
    for (int i = 0; i < privacies.size(); i++) {
        char term = privacies[i][privacies[i].size()-1];
        string tmp = "";
                
        for (int j = 0; j < terms.size(); j++) {
            if (terms[j][0] == term) {
                for (int k = 2; k < terms[j].size(); k++) {
                    tmp += terms[j][k];
                }
                break;
            }
        }
        int targetD, targetM, targetY;
        
        bool monthDown = false;
        if (stoi(privacies[i].substr(8,2)) == 1) {
            monthDown = true;
            targetD = 28;
        }
        else {
            targetD = stoi(privacies[i].substr(8,2))-1;
        }
        if (stoi(privacies[i].substr(5,2))+stoi(tmp) > 12) {
            targetM = (stoi(privacies[i].substr(5,2))+stoi(tmp))%12;
            if (targetM == 0)
                targetM = 12;
            targetY = stoi(privacies[i].substr(0,4)) + (stoi(privacies[i].substr(5,2))+stoi(tmp))/12;
            if ((stoi(privacies[i].substr(5,2))+stoi(tmp))%12==0)
                targetY--;
        }
        else {
            targetM = stoi(privacies[i].substr(5,2))+stoi(tmp);
            targetY = stoi(privacies[i].substr(0,4));
        }
        if (monthDown) {
            targetM--;
            if (targetM == 0) {
                targetM = 12;
                targetY--;
            }
        }
        
        cout << targetY << ' ' << targetM <<' ' << targetD << '\n';
        
        if (targetY > todayY) {
            continue;
        }
        else if (targetY < todayY) {
            answer.push_back(i+1);
            continue;
        }
        else {
            if (targetM > todayM) {
                continue;
            }
            else if (targetM < todayM) {
                answer.push_back(i+1);
                continue;
            }
            else {
                if (targetD < todayD) {
                    answer.push_back(i+1);
                }
            }
        }
    }
    
    return answer;
}