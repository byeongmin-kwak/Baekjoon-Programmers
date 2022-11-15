#include <bits/stdc++.h>

using namespace std;


int main() {
        
    int N;
    cin >> N;

    string s;
    cin >> s;

    double arr[26];

    stack<double> st1;

    for (int i = 0 ; i < N; i++) {
        cin >> arr[i];

    }

    double a, b;
    double result;

    for (int i = 0 ; i < s.size(); i++) {
        if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
            b = st1.top();
            st1.pop();
            a = st1.top();
            st1.pop();
            switch (s[i]) {
                case '+':
                    result = a + b;
                    st1.push(result);
                    break;
                case '-':
                    result = a - b;
                    st1.push(result);
                    break;
                case '*':
                    result = a * b;
                    st1.push(result);
                    break;
                case '/':
                    result = a / b;
                    st1.push(result);
                    break;
                default:
                    break;
            }
        }
        else {
            st1.push(arr[int(s[i]) - 65]);
        }
    }



    cout<<fixed;
    cout.precision(2);
    cout << st1.top();
    

    
    cout << endl;
    
    return 0;
}
