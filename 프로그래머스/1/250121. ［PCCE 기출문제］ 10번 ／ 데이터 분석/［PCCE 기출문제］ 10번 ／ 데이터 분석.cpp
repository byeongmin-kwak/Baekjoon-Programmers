#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sort_byIdx;

bool compare(vector<int>& a, vector<int>& b) {
    return a[sort_byIdx] < b[sort_byIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    vector<string> ext2 = {"code", "date", "maximum", "remain"};
    
    int extIdx = -1;
    for (int i = 0; i < ext2.size(); i++) {
        if (ext2[i] == ext) {
            extIdx = i;
        }
        if (ext2[i] == sort_by) {
            sort_byIdx = i;
        }
    }
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i][extIdx] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}