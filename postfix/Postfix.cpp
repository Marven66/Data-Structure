#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePostfix(const string& expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (token[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string expr = "5 3 + 8 *";
    cout << evaluatePostfix(expr) << endl;
    return 0;
}
