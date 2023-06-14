#include <string>
#include <vector>

using namespace std;

vector<int> v1;

int solution(vector<int> v) {
    
    int cnt = 0;
    
    for (int i = 0; i < v.size(); i++) {
        v1.push_back(v[i]);
        
        if (v1.size() >= 4) {
            int check = 0;
            
            for (int i = 0; i < 4; i++) {
                if (check == 0) {
                    if (v1[v1.size()-4+i] != 1) {
                        break;
                    }
                    else {
                        check++;
                    }
                }
                else if (check == 1) {
                    if (v1[v1.size()-4+i] != 2) {
                        break;
                    }
                    else {
                        check++;
                    }
                }
                else if (check == 2) {
                    if (v1[v1.size()-4+i] != 3)
                        break;
                    else {
                        check++;
                    }
                }
                else if (check == 3) {
                    if (v1[v1.size()-4+i] != 1) {
                        break;
                    }
                    else {
                        cnt++;
                        for (int i = 0; i < 4; i++) {
                            v1.pop_back();
                        }
                    }
                }
            }
        }
    }

    int answer = cnt;
    return answer;
}