#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int minute(string in, string out) {
    int a = stoi(in.substr(0,2)) * 60 + stoi(in.substr(3,2));
    int b = stoi(out.substr(0,2)) * 60 + stoi(out.substr(3,2));
    
    return b - a;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    vector<string> number;
    vector<pair<string,int>> info(1001);
    map<string, int> m;
    
    int cnt = 1;
    for (auto elem : records) {
        string time = elem.substr(0,5);
        string carNum = elem.substr(6,4);
        string IN_OUT = elem.substr(11);
        
        if (m[carNum] == 0) {
            m[carNum] = cnt;
            number.push_back(carNum);
            cnt++;
        }
        
        if (IN_OUT == "IN") {
            info[m[carNum]].first = time;
        }
        else {
            info[m[carNum]].second += minute(info[m[carNum]].first, time);
            info[m[carNum]].first = " ";
        }
    }
    
    
    sort(number.begin(), number.end());
    for (auto elem : number) {
        if (info[m[elem]].first != " ") {
            info[m[elem]].second += minute(info[m[elem]].first, "23:59");
        }
        if (info[m[elem]].second < fees[0]) {
            answer.push_back(fees[1]);
        }
        else {
            int tmp = (info[m[elem]].second - fees[0]) / fees[2];
            if ((info[m[elem]].second - fees[0]) % fees[2] > 0) {
                tmp += 1;
            }
            tmp *= fees[3];
            tmp += fees[1];
            answer.push_back(tmp);
        }
    }
    
    return answer;
    
    
}