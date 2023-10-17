#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int delivery = 0, pickup = 0;
    
    for (int i = 0; i < n; i++) {
        delivery += deliveries[i];
        pickup += pickups[i];
    }
    
    int endDelivery = n-1, endPickup = n-1;
    int current;
    while (delivery > 0 || pickup > 0) {
        
        current = cap;
        int tmp1 = 0;
        bool flag = false;
        //남은 개수 중 최대치를 실어서 끌까지 배달
        if (delivery > 0) {
            for (int i = endDelivery; i >= 0; i--) {
                if (!flag && deliveries[i] != 0) {
                    flag = true;
                    tmp1 = i+1;
                }

                if (current >= deliveries[i]) {
                    current -= deliveries[i];
                    deliveries[i] = 0;
                }
                else {
                    deliveries[i] -= current;
                    current = 0;
                }
                if (current == 0) {
                    endDelivery = i;
                    break;
                }
            }
            delivery -= cap;
        }
        
        current = 0;
        int tmp2 = 0;
        flag = false;
        //끝에서부터 최대치 수거
        if (pickup > 0) {
            for (int i = endPickup; i >= 0; i--) {
                if (!flag && pickups[i] != 0) {
                    flag = true;
                    tmp2 = i+1;
                }

                if (current + pickups[i] <= cap) {
                    current += pickups[i];
                    pickups[i] = 0;
                }
                else {
                    pickups[i] -= cap-current;
                    current = cap;
                }
                if (current == cap) {
                    endPickup = i;
                    break;
                }
            }
            pickup -= cap;
        }
        
        //배달과 수거 거리중 최댓값 * 2
        answer += max(tmp1, tmp2) * 2;
        //cout << tmp1 << ' ' << tmp2 << ' ' <<  delivery << ' ' << pickup << ' ' << answer << endl;
    }

    return answer;
}