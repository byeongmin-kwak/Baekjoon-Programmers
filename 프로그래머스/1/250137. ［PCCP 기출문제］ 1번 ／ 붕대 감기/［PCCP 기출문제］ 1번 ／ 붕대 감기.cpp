#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int maxTime = attacks[attacks.size()-1][0];
    
    int attacksIdx = 0;
    int success = 0;
    int currentHealth = health;
    
    for (int i = 0; i <= maxTime; i++) {
        if (attacks[attacksIdx][0] == i) {
            currentHealth -= attacks[attacksIdx][1];
            success = 0;
            attacksIdx++;
            if (currentHealth <= 0) return -1; 
        } else {
            currentHealth += bandage[1];
            success++;
            if (success == bandage[0]) {
                currentHealth += bandage[2];
                success = 0;
            }
            if (currentHealth > health) {
                currentHealth = health;
            }
        }
        cout << currentHealth << endl;
        answer = currentHealth;
    }
    
    return answer;
}